from typing import List

class pySolution(object):
    def py_Candy(self, ratings: List[int]) -> int:
        n: int = len(ratings)                   # 📏 Number of kids
        candies: List[int] = [1] * n            # 🍬 Start: everyone gets 1 candy

        # 🔁 Adjust candies based on neighbors’ ratings
        for index in range(n):

            # 🔹 Left neighbor check: if you're rated higher, get more candy
            if index > 0:
                candies[index] = (candies[index - 1] + 1
                                  if ratings[index] > ratings[index - 1] and candies[index] <= candies[index - 1]
                                  else candies[index])

            # 🔹 Right neighbor check: don’t get out-candied by your neighbor
            if index < n - 1:
                candies[index] = (candies[index + 1] + 1
                                  if ratings[index] > ratings[index + 1] and candies[index] <= candies[index + 1]
                                  else candies[index])

            # 🔄 Forward pass: make sure kids ahead are fair too
            for currentIndex in range(index + 1, n):
                candies[currentIndex] = (candies[currentIndex - 1] + 1
                                         if ratings[currentIndex] > ratings[currentIndex - 1] and 
                                            candies[currentIndex] <= candies[currentIndex - 1]
                                         else candies[currentIndex])

            # 🔄 Backward pass: and don’t forget kids behind!
            for currentIndex in range(index - 1, -1, -1):
                candies[currentIndex] = (candies[currentIndex + 1] + 1
                                         if ratings[currentIndex] > ratings[currentIndex + 1] and 
                                            candies[currentIndex] <= candies[currentIndex + 1]
                                         else candies[currentIndex])

        totalCandies: int = sum(candies)    # 💰 Sum up all candies to get the total
        del(candies)                        # 🧹 Cleanup: remove the list to free memory

        return totalCandies                 # 🎯 Mission accomplished: everyone’s happy!