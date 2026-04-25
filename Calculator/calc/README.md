# Integer Expression Finder — C Implementation

A project I wrote to find all arithmetic expressions, built from a given set of integers, that evaluate to a target value.

## How It Works
The program combines two search strategies:

1. **Permutation generation** — uses backtracking to produce every ordering of the input numbers
2. **Operator enumeration** — for each number ordering, tries all possible combinations of `+`, `-`, `*`, `/` between operands

All expressions are evaluated strictly left-to-right with no precedence rules (integer division, division by zero skipped). Any expression that hits the target is printed.

## Key Functions
- `operation(a, b, op)` — applies one operator and returns the integer result
- `evaluate(sol, n, result)` — loops over all `4^(n-1)` operator combinations for a fixed number ordering
- `simple_permutation(...)` — recursive backtracking that fills every permutation of the input array
- `calculator(v, n, result)` — allocates workspace and kicks off the search

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./Calculator
```

## Notes
- All operators share equal precedence; evaluation is strictly left-to-right
- Integer division truncates toward zero; division by zero is silently skipped
- Standard C only — no external dependencies
