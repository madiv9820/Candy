## 🍬 Candy Distribution – Brute Force Approach
You have `n` children standing in a line, each with a rating 👦👧.
Your goal is to **distribute candies** 🍭 according to these rules:
1. Every child must get **at least 1 candy** 🥇
2. Children with a **higher rating than their neighbors** get **more candies** ⬆️

This approach uses a **brute-force strategy** to satisfy the conditions.

### 🔹 How It Works
1. **Initialize candies**
    - Give **1 candy** to each child 🍬
    - Ensures no kid is left candy-less

2. **Iterate** through each child 🔁
    - **Left neighbor check:** if the current child has a higher rating than the left neighbor and has ≤ candies, give 1 extra candy ⬆️
    - **Right neighbor check:** same logic for the right neighbor

3. **Propagate changes** 🔄
    - After adjusting the current child, **neighbors might now violate the rules**
    - **Backward pass:** update left neighbors
    - **Forward pass:** update right neighbors
    - Repeat for all children until all conditions are satisfied

4. **Sum total candies** 💰
    - Add up all candies in the array to get the **minimum total required**

### ⏱️ Complexity
- **⏰ Time Complexity:**
    - Nested forward/backward passes → worst-case `O(n²)` ⚠️
    - Works fine for small inputs, but slow for large arrays (e.g., n > 10⁴) 🐢

- **📦 Space Complexity:**
    - Maintain a candies array of size n → `O(n)` 💾
    - Only extra space is loop variables 🧹

- ⚡ Note: This brute-force approach is simple and intuitive — great for learning and validation.
For large datasets, an **optimized linear solution** exists that reduces time to O(n) 🚀
---