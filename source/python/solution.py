from typing import List

class pySolution(object):
    def py_Candy(self, ratings: List[int]) -> int:
        n: int = len(ratings)                     # 📏 Number of kids
        candies: List[int] = [1] * n              # 🍬 Start: everyone gets 1 candy

        # 1️⃣ Forward pass → check left neighbor 👈
        # If current child has higher rating than left neighbor, give extra candy
        for index in range(1, n):
            candies[index] = (candies[index - 1] + 1
                              if ratings[index] > ratings[index - 1] and candies[index] <= candies[index - 1]
                              else candies[index])
        
        # 2️⃣ Backward pass → check right neighbor 👉
        # If current child has higher rating than right neighbor, adjust candy count
        for index in range(n - 2, -1, -1):
            candies[index] = (candies[index + 1] + 1
                              if ratings[index] > ratings[index + 1] and candies[index] <= candies[index + 1]
                              else candies[index])

        totalCandies: int = sum(candies)    # 3️⃣ Sum all candies 💰
        del(candies)                        # 🧹 Cleanup memory (optional)

        return totalCandies                 # 🎯 Return minimum total candies