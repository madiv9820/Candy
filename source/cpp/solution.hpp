#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();               // 📏 Number of kids
        vector<int> candies(n, 1);            // 🍬 Start: everyone gets 1 candy

        // 1️⃣ Forward pass → check left neighbor 👈
        // If current kid has higher rating than the left neighbor, give one extra candy
        for(int index = 1; index < n; ++index) {
            candies[index] = ((ratings[index] > ratings[index - 1] && 
                               candies[index] <= candies[index - 1]) ? 
                               candies[index - 1] + 1 : candies[index]);
        }

        // 2️⃣ Backward pass → check right neighbor 👉
        // If current kid has higher rating than the right neighbor, adjust candies
        for(int index = n - 2; index >= 0; --index) {
            candies[index] = ((ratings[index] > ratings[index + 1] && 
                               candies[index] <= candies[index + 1]) ? 
                               candies[index + 1] + 1 : candies[index]);
        }

        int totalCandies = accumulate(candies.begin(), candies.end(), 0);   // 3️⃣ Sum all candies 💰
        vector<int>().swap(candies);                                        // 🧹 Optional: clear vector to free memory
        
        return totalCandies;            // 🎯 Return minimum total candies
    }
};

#endif