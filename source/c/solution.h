#ifndef SOLUTION_H
#define SOLUTION_H

#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    // 🗃️ Array to track candies for each child
    int* candies = (int*) calloc(ratingsSize, sizeof(int));
    int totalCandies = 0;  // 💰 Total candies to give
    int index;             // 🔁 Loop variable

    // 1️⃣ Step 1: Give everyone at least 1 candy 🍬
    for(index = 0; index < ratingsSize; ++index) { 
        candies[index] = 1; 
    }

    // 2️⃣ Step 2: Forward pass → check left neighbor 👈
    // If current child has higher rating than the left neighbor, give one extra candy
    for(index = 1; index < ratingsSize; ++index) {
        candies[index] = ((ratings[index] > ratings[index - 1] && 
                           candies[index] <= candies[index - 1]) ? 
                           candies[index - 1] + 1 : candies[index]);
    }

    // 3️⃣ Step 3: Backward pass → check right neighbor 👉
    // Ensure children with higher rating than right neighbor get more candies
    for(index = ratingsSize - 2; index >= 0; --index) {
        candies[index] = ((ratings[index] > ratings[index + 1] && 
                           candies[index] <= candies[index + 1]) ? 
                           candies[index + 1] + 1 : candies[index]);
    }

    // 4️⃣ Step 4: Sum up all candies 💰
    for(index = 0; index < ratingsSize; ++index) { 
        totalCandies += candies[index]; 
    }
    
    free(candies);          // 🧹 Step 5: Free allocated memory to avoid leaks
    return totalCandies;    // 🎯 Return the minimum total candies
}

#endif