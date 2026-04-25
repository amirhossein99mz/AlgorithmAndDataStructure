# Graph Coloring — C Implementation

A project I wrote to find the minimum number of colors needed to color an undirected graph so that no two adjacent vertices share the same color.

## How It Works
The algorithm uses backtracking. It tries to assign a color to each vertex one by one. Before assigning a color, it checks that no neighboring vertex already holds it. If no valid color fits, it backtracks and tries the next option. The outer loop starts with just 1 color and increments until a valid coloring is found — guaranteeing the minimum.

## Key Functions
- `isSafe(graph, n, v, color, colors)` — returns 1 if assigning `color` to vertex `v` doesn't conflict with its neighbors
- `solve(graph, n, v, maxColors, colors)` — recursive backtracking over all vertices; returns 1 on success
- `color(graph, n)` — tries 1, 2, ... n colors until `solve` succeeds; prints the result

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./GraphColoring
```

## Notes
- Graph is represented as an `int**` adjacency matrix
- Colors are integers starting from 1
- Standard C only — no external dependencies
