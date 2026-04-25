# Diagonal Average Matrix — C Implementation

A project I wrote to process a 2D integer matrix by replacing each element with the average of all values on both diagonals passing through that position.

## How It Works
For every cell `[i][j]`, the function walks outward in all four diagonal directions (right-bottom, right-top, left-top, left-bottom), collecting values until it hits a matrix boundary. It counts how many elements were found (including the cell itself) and divides the accumulated sum to get the float average.

## Key Points
- The center element is always included in the count
- Boundary cells naturally have fewer diagonal neighbors, so the count varies per cell
- Result is stored as `float` to preserve decimal precision

## Files
- `main.c` — `avg()` function + demo `main()` with the sample 3×5 matrix
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./DiagonalAverage
```

## Notes
- Matrix dimensions are set via `#define R` and `#define C` at the top of `main.c`
- Standard C only — no external dependencies
