# Matrix Compress — C Implementation

A utility I wrote to deduplicate a 2D char matrix in-place, shrinking it down to only its unique rows and columns.

## What It Does
Given a `char**` matrix, the `compress` function:
1. Scans for rows that are identical and removes the later occurrences
2. Repeats the same process column-wise
3. Updates the row and column counts to match the reduced matrix
4. Returns the compacted matrix

The whole thing happens in-place — no extra matrix is allocated.

## Files
- `main.c` — core function + helper printer + demo main
- `CMakeLists.txt` — build config for CLion / CMake

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./MatrixCompress
```

## Example
Input (5 × 6):
```
1 2 3 4 5 1
1 2 3 4 5 1
6 7 8 9 0 6
6 7 8 9 0 6
1 3 5 7 9 1
```
Output (3 × 5):
```
1 2 3 4 5
6 7 8 9 0
1 3 5 7 9
```

## Notes
- Rows are `char*` arrays, so each cell is a single `char`
- Duplicate removal preserves the first occurrence
- Standard C only — no external dependencies
