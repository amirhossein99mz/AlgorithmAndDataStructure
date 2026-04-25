# Isomorphic Tree — C Implementation

A small C project I built to explore recursive tree comparison.

## Overview
This project implements a binary tree comparison utility in C.
The core idea is checking whether two trees have the same shape and data,
even if some subtrees are flipped. I used dynamic strings as node values
to make it a bit more realistic than plain integers.

## How It Works
The main function walks both trees simultaneously. At each node it tries
two paths: comparing children in the same order, and comparing them
cross-wise. If either path succeeds all the way down, the trees match.

## Files
- `isomorphic_tree.c` — data structure definition + full implementation + main demo
- `CMakeLists.txt` — build config for CLion / CMake

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./IsomorphicTree
```

## Notes
- Node values are heap-allocated strings (`char *data`)
- No external libraries used — standard C only
- Recursion bottoms out at NULL nodes
