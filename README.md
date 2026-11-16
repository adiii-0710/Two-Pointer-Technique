# Two-Pointer Technique

A programming assignment demonstrating brute-force and optimized solutions to two problems on sorted arrays, implemented in **C++**, **Java**, and **Python**.

## Problems

- **Remove duplicates:** Keep one copy of each value in a sorted array. The optimized approach uses slow and fast pointers and updates the array in place.
- **Pair sum:** Find two distinct indices whose values add up to a target. The optimized approach moves pointers inward from opposite ends of a sorted array.

Each language implementation includes brute-force and optimized methods, plus sample test cases.

## Complexity

| Problem | Approach | Time | Extra space |
|---|---|---:|---:|
| Remove duplicates | Brute force | O(n²) | O(n) |
| Remove duplicates | Two pointers | O(n) | O(1) |
| Pair sum | Brute force | O(n²) | O(1) |
| Pair sum | Two pointers | O(n) | O(1) |

## Run the examples

### C++

```bash
g++ -std=c++17 Assignment1.cpp -o assignment
./assignment
```

### Java

```bash
javac Assignment1.java
java Assignment1
```

### Python

```bash
python3 Assignment1.py
```

**Note:** Both optimized methods rely on the input array being sorted. Pair-sum results use zero-based indices; `(-1, -1)` indicates that no matching pair was found.
