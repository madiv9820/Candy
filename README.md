## 🍬 Candy Distribution – Optimized Two-Pass Approach

Distribute candies to children standing in a line 👦👧 based on their ratings:
1. Every child must get **at least 1 candy** 🥇
2. Children with **a higher rating than their neighbors** get more candies ⬆️

This implementation uses **an optimized two-pass strategy** for efficiency.

### 🔹 How It Works
1. **Initialize candies 🍬**
    - Give **1 candy** to each child. Everyone deserves at least one!
2. **Forward pass 👈**
    - Traverse left to right
    - If the current child has a **higher rating than the left neighbor**, give **1 extra candy**
3. **Backward pass 👉**
    - Traverse right to left
    - If the current child has a **higher rating than the right neighbor**, adjust candies to satisfy the rules
4. **Sum total candies 💰**
    - Add all candies to get the **minimum total required**

### ⏱️ Complexity
- **⏰ Time Complexity:** `O(n)` → only **two passes over the array** ⚡
- **📦 Space Complexity:** `O(n)` → extra **candies array** 💾
---