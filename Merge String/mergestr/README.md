# Merge String — C Implementation

A project I wrote to merge two sorted lowercase strings into a single sorted string, using the classic two-pointer merge algorithm with an extra merge-sort pass for safety.

## How It Works
Before merging, the function validates that both strings contain only lowercase letters arranged in non-decreasing order. It then walks both strings simultaneously with two pointers, always picking the smaller character, and appends any remaining characters at the end. A recursive merge sort is applied to the result as a final correctness guarantee.

## Key Functions
- `is_valid(s)` — checks that the string is all lowercase and sorted ascending
- `mergeSort(arr, arr2, left, middle, right)` — standard merge step: merges two sorted halves using a temp buffer
- `merge(arr, left, right)` — recursive divide-and-conquer driver for merge sort
- `merge_string(s1, s2)` — validates inputs, runs the two-pointer merge, and returns a heap-allocated result

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./MergeString
```

## Notes
- Caller is responsible for `free()`-ing the returned string
- Returns `NULL` if either input fails validation
- Standard C only — uses `<ctype.h>` for `islower`
