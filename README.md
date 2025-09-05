# 🧮 push_swap-42

> **push_swap-42** is a custom implementation of a sorting algorithm designed to arrange a list of integers in ascending order using a limited set of operations. Developed as part of the 42 School curriculum, this project delves into algorithm optimization, stack manipulation, and performance benchmarking.

---

## 📌 Project Overview

**push_swap-42** aims to:

- Sort a list of integers using two stacks (`a` and `b`).
- Minimize the number of operations required to achieve the sorted order.
- Implement a checker program to verify the correctness of the sorting instructions.

By completing this project, you will gain hands-on experience with:

- Designing efficient sorting algorithms.
- Manipulating data structures using a limited set of operations.
- Analyzing and optimizing algorithmic performance.

---

## ✨ Features

- **Sorting Algorithm Implementation:** Custom algorithm tailored for stack manipulation.
- **Instruction Set:** `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, `ss`, `rr`, `rrr`.
- **Checker Program:** Verifies if a sequence of operations correctly sorts the stack.
- **Performance Optimization:** Sort with the fewest operations.
- **Error Handling:** Handles invalid inputs and edge cases gracefully.

---

## 🛠 Technologies Used

- **Programming Language:** C
- **Data Structures:** Stacks (linked lists)
- **Algorithm Design:** Custom sorting algorithm with partitioning and stack rotations
- **Build System:** Makefile
- **Version Control:** Git & GitHub
- **Operating Systems:** Linux (Ubuntu 22.04), macOS

---

## 🧠 Algorithm & Logic

The **push_swap-42** algorithm combines stack operations and partitioning to sort efficiently:

1. **Initialization:**
   - Parse the input numbers.
   - Store them in **Stack A**.
   - Initialize **Stack B** as empty.

2. **Check for Small Cases:**
   - If 2–3 numbers, use minimal swaps (`sa`, `ra`, `rra`) to sort.
   - If 4–5 numbers, push smallest elements to Stack B and sort the rest in Stack A.

3. **Main Sorting Logic (for larger sets):**
   - **Divide & Conquer:**
     - Split Stack A into smaller partitions based on **pivot values** (median or quarter values).
     - Push elements less than the pivot to Stack B using `pb`.
   - **Recursive Sorting:**
     - Sort the remaining elements in Stack A using rotation and swap operations.
     - Push back elements from Stack B to Stack A in the correct order using `pa`.
   - **Rotation Optimization:**
     - Use `ra`/`rb` and `rra`/`rrb` strategically to minimize moves.
     - Combine operations (`rr`, `rrr`, `ss`) where possible.

4. **Final Adjustment:**
   - Rotate Stack A until the smallest number is at the top.
   - Ensure Stack A is fully sorted.

5. **Checker:**
   - The `checker` program reads operations from input.
   - Simulates the operations on Stack A and B.
   - Confirms if Stack A is sorted and Stack B is empty.

---

## 📌 Usage

```bash
make
./push_swap <list_of_numbers>
./checker <list_of_numbers>
