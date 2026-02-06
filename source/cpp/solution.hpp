#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();                 // 📏 Number of kids
        vector<int> candies(n, 1);              // 🍬 Start: everyone gets 1 candy

        // 🔁 Adjust candies according to neighbor ratings
        for(int index = 0; index < n; ++index) {

            // 🔹 Left neighbor check: if you're rated higher, get more candy
            if(index > 0) {
                candies[index] = ((ratings[index] > ratings[index - 1] &&
                                    candies[index] <= candies[index - 1]) ?
                                    candies[index - 1] + 1 : candies[index]);
            }

            // 🔹 Right neighbor check: don't get out-candied by your neighbor
            if(index < n - 1) {
                candies[index] = ((ratings[index] > ratings[index + 1] &&
                                    candies[index] <= candies[index + 1]) ?
                                    candies[index + 1] + 1 : candies[index]);
            }

            // 🔄 Backward pass: make sure left neighbors are fair too
            for(int currentIndex = index - 1; currentIndex >= 0; --currentIndex) {
                candies[currentIndex] = ((ratings[currentIndex] > ratings[currentIndex + 1] &&
                                        candies[currentIndex] <= candies[currentIndex + 1]) ?
                                        candies[currentIndex + 1] + 1 : candies[currentIndex]);
            }

            // 🔄 Forward pass: and forward neighbors too
            for(int currentIndex = index + 1; currentIndex < n; ++currentIndex) {
                candies[currentIndex] = ((ratings[currentIndex] > ratings[currentIndex - 1] &&
                                        candies[currentIndex] <= candies[currentIndex - 1]) ?
                                        candies[currentIndex - 1] + 1 : candies[currentIndex]);
            }
        }

        // 💰 Sum up all candies to get total
        int totalCandies = accumulate(candies.begin(), candies.end(), 0);

        // 🧹 Free memory (optional cleanup, just in case)
        vector<int>().swap(candies);

        return totalCandies; // 🎯 Return the minimum total candies
    }
};

#endif