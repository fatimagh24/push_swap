# Push_Swap

## 🚀 Overview
**Push_Swap** is a project that focuses on sorting a stack of integers using a limited set of operations.  
The goal is to write a program that sorts the numbers **with the least possible moves**, demonstrating algorithmic thinking and efficiency.

This implementation uses the **Radix Sort algorithm** to handle larger stacks efficiently.

---

## 🛠 Features
- Sorts a stack of integers using only allowed operations:
  - `sa`, `sb`, `ss` (swap)
  - `pa`, `pb` (push)
  - `ra`, `rb`, `rr` (rotate)
  - `rra`, `rrb`, `rrr` (reverse rotate)
- Supports any number of integers provided as input
- Efficient sorting using **Radix Sort** for large sets

---

## ⚡ Usage

```bash
# Compile the program
make

# Run the program
./push_swap 3 2 1 6 5 4
