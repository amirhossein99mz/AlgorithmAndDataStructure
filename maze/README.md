# Exercise 16 – Maximum Sum Path in a Matrix

## Problem Description

You are given a grid (matrix) of integers. Think of it like a map where:

- You **start** at the **top-left cell** `[0,0]`
- You **end** at the **bottom-right cell** `[r-1, c-1]`
- From any cell, you can move to any of its **up to 8 neighbours** (horizontally, vertically, or diagonally)
- You can **visit each cell only once**

Your goal is to find a path from start to end such that the **sum of all visited cell values is as large as possible**.

---

## Function Signature

```c
void mat_visit(int **mat, int r, int c, int f);
```

| Parameter | Meaning |
|-----------|---------|
| `mat` | The integer matrix |
| `r` | Number of rows |
| `c` | Number of columns |
| `f` | Tiebreaker flag |

---

## Tiebreaker Rule (`f` flag)

When **multiple paths share the same maximum sum**:

| `f` value | Behaviour |
|-----------|-----------|
| `0` | Print the **shortest** path among the best ones |
| `1` | Print the **longest** path among the best ones |

---

## Output Format

Each visited cell is printed as `[row,col]value`, separated by ` - `:

```
[0,0]1 - [0,1]2 - [1,0]9 - [2,1]1 - [1,2]7 - [2,2]4 - sum = 24
```

---

## Approach

The solution uses **recursive DFS (Depth-First Search)** with backtracking:

1. Start at `[0,0]` and explore all 8 directions recursively
2. Keep track of visited cells to avoid revisiting
3. When the bottom-right corner is reached, compare the current path's sum (and length) against the best found so far
4. Update the best path accordingly, respecting the `f` flag for tiebreaking
5. After recursion, **backtrack** (unmark the current cell as visited) so other paths can use it

**Data structures used:**
- `sol[][]` – a 2D array storing the current path being explored (row, col, value per step)
- `best[][]` – a copy of the best path found so far
- `visited[][]` – a boolean matrix tracking which cells have already been used in the current path

---

## Files

| File | Description |
|------|-------------|
| `mat_visit.c` | Full C implementation of the solution |

---

## How to Compile and Run

```bash
gcc -o exercise16 mat_visit.c
./exercise16
```
