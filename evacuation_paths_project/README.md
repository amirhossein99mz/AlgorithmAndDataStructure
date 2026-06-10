# Evacuation Paths Project

This project contains a C program (`path.c`) that finds all valid evacuation paths in a city grid.

## Description

- The city is represented as a 2D grid with travel costs in each cell.
- Each path starts at `src_city` and ends at `dst_city`.
- The total cost of the path cannot exceed a given budget.
- Movement is allowed along edges with positive cost only.
- Each city is visited at most once per path.
- All valid paths are printed along with their total cost.

## Files

- `path.c` : C source code implementing DFS to find all valid paths.
- `README.md` : This documentation file.

## Compilation & Execution

```bash
gcc path.c -o path
./path
```

The program prints each valid path and its cost.
