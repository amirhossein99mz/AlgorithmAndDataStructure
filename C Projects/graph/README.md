# Graph Cycles — C Implementation

A project I wrote to find all simple cycles of a given length in a directed graph, using DFS and backtracking.

## How It Works
The graph is stored as an adjacency matrix. Starting from every node, a recursive DFS explores paths of increasing depth. When the path reaches the target length and an edge back to the starting node exists, the cycle is printed. Backtracking resets the visited state so different paths can be explored from the same start.

## Data Structure
- `Graph` — struct holding the number of vertices and a 2D adjacency matrix (`int **`)

## Key Functions
- `createGraph(nv)` — allocates a zeroed adjacency matrix for `nv` vertices
- `cycle(...)` — recursive DFS that tracks depth, start node, current node, and visited state
- `loop(mat, n, k)` — launches the search from every node for cycles of length `k`
- `printGraph(path, k)` — prints one discovered cycle

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./GraphCycles
```

## Notes
- Adjacency matrix uses `calloc` so all edges start at 0
- `visited[]` is reset (backtracked) after each recursive call
- Standard C only — no external dependencies
