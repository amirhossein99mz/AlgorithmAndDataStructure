# Load Truck — C Implementation

A recursive combinatorial search I implemented to find the subset of parcels that maximizes total value while staying within a truck's weight limit.

## How It Works
The function generates all possible subsets of parcels using recursive combination. At each step it picks the next parcel to include, accumulates weight and value, and recurses. Once a full combination is assembled, it checks whether the total weight fits the truck and whether the total value beats the current best. If so, the best solution is updated.

## Global State
- `max_euro` — best total value found so far
- `best_euro` / `best_weight` — arrays storing the value and weight of each selected parcel in the best solution

## Key Functions
- `simple_combination(...)` — recursive engine; builds subsets via backtracking and updates globals when a better solution is found
- `load_truck(weight, value, n, load)` — allocates workspace and kicks off the search
- `print(...)` — displays the best solution

## Files
- `main.c` — full implementation + demo `main()` with the example from the exercise
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./LoadTruck
```

## Notes
- Values and weights are cast to `int` internally (consistent with the original global declarations)
- Standard C only — no external dependencies
