#ifndef SOLUTION_H
#define SOLUTION_H

#include <stdlib.h> // 🏗️ For calloc & free (building stuff safely)

int candy(int* ratings, int ratingsSize) {
    int totalCandies = 0;                               // 💰 Total candy stash
    int *candies = calloc(ratingsSize, sizeof(int));    // 🗃️ Candy array for each kid
    int index, currentIndex;                            // 🔁 Loop buddies

   
    for(index = 0; index < ratingsSize; ++index) {
        candies[index] = 1;                              // 1️⃣ Give everyone 1 candy to start 🍭
    }

    // 2️⃣ Now comes the tricky part: comparing with neighbors 👀
    for(index = 0; index < ratingsSize; ++index) {

        // 🔹 Check left neighbor: if you’re rated higher, get more candy
        if(index > 0) {
            candies[index] = ((ratings[index] > ratings[index - 1] && 
                              candies[index] <= candies[index - 1]) ? 
                              candies[index - 1] + 1 : candies[index]);
        }

        // 🔹 Check right neighbor: don’t let them out-candy you!
        if(index < ratingsSize-1) {
            candies[index] = ((ratings[index] > ratings[index + 1] && 
                              candies[index] <= candies[index + 1]) ? 
                              candies[index + 1] + 1 : candies[index]);
        }

        // 🔄 Backward pass: “hey lefties, get your candy fixed too!”  
        for(currentIndex = index - 1; currentIndex >= 0; --currentIndex) {
            candies[currentIndex] = ((ratings[currentIndex] > ratings[currentIndex + 1] && 
                                      candies[currentIndex] <= candies[currentIndex + 1]) ? 
                                      candies[currentIndex + 1] + 1 : candies[currentIndex]);
        }

        // 🔄 Forward pass: “and righties, don’t be left behind!”  
        for(currentIndex = index + 1; currentIndex < ratingsSize; ++currentIndex) {
            candies[currentIndex] = ((ratings[currentIndex] > ratings[currentIndex - 1] && 
                              candies[currentIndex] <= candies[currentIndex - 1]) ? 
                              candies[currentIndex - 1] + 1 : candies[currentIndex]);
        }
    }
  
    for(index = 0; index < ratingsSize; ++index) {
        totalCandies += candies[index];     // 3️⃣ Count all candies 🍬💰
    }

    free(candies);                          // 🧹 Free memory: no candy wrappers left lying around!
    return totalCandies;                    // 🎯 Everyone’s happy, mission complete!
}

#endif