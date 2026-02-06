# [Candy 🍬](https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150)

You’ve got `n` kids standing in a line, each with a **rating** 🎖️ given in the array `ratings`.

**Rules:**
1. Every kid must get **at least 1 candy 🍫**
2. Kids with **higher ratings than their neighbors** must get **more candies** 😎

**Goal:** <br>
Find the **minimum number of candies** needed so that everyone’s happy and no one feels left out. 🏆

**Meme vibe:** *“You think 1 candy is enough? I’m rated higher than him!”* 😤🍬

### 🍬 Example 1
- **Input:** `ratings = [1,0,2]`
- **Output:** `5`
- **Candy distribution:** `[2,1,2]` 🍭👦🍬
- **Explanation:**
    - The first child gets 2 candies because the next kid has a lower rating.
    - The middle child gets 1 candy (minimum).
    - The last child gets 2 candies because their rating is higher than the middle child. 😎

### 🍬 Example 2
- **Input:** `ratings = [1,2,2]`
- **Output**: `4`
- **Candy distribution:** `[1,2,1]` 🍬👦🍭
- **Explanation:**
    - The first child gets 1 candy.
    - The second child gets 2 candies because their rating is higher than the first child.
    - The third child gets 1 candy — enough to satisfy the rules since its rating isn’t higher than its neighbor. ✅

### ⚡ Constraints
- `n == ratings.length` 📏
- `1 <= n <= 20,000` 👶👦👧…
- `0 <= ratings[i] <= 20,000` 🎖️

## 🧠 Approaches
1. ### [Brute-Force Approach](https://github.com/madiv9820/Candy/tree/Approach_01-Brute_Force)
    - Give 1 candy to everyone and adjust candies by repeatedly checking neighbors 🔁.
    - Forward & backward passes until all conditions are satisfied 🔄 — simple but slow for large inputs 🐢.

2. ### [Optimized Two-Pass Approach](https://github.com/madiv9820/Candy/tree/Approach_02-Greedy)
    - Give 1 candy to everyone, then do a forward pass (left → right) ⬆️ and a backward pass (right → left) ⬆️.
    - Efficient, neat, and works well for large arrays ⚡ — calculates minimum total candies 💰.
---