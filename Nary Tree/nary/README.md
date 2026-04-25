# N-ary Tree Level Analyzer — C Implementation

A project I built to find the most populated depth level in an n-ary tree using BFS, and print all node keys at that level.

## How It Works
The tree is traversed level by level using a queue. At each depth, all nodes for that level are dequeued at once and their children are enqueued for the next round. The depth with the highest node count is recorded, and its keys are printed.

## Data Structures
- `node_t` — tree node holding an integer key, a dynamic array of child pointers, and the child count
- `Queue` — array-based FIFO queue used to drive the BFS traversal

## Key Functions
- `create_node(data, children_length)` — allocates a node with a pre-sized children array
- `free_node(node)` — recursively frees a node and its children array
- `queue_create / equeue / dequeue / isEmpty` — minimal queue operations for BFS
- `display_crowded_depth(root)` — BFS traversal that finds and prints the busiest depth, returns its index

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./NaryTree
```

## Notes
- Root is at depth 0
- Queue capacity is fixed at 100; increase for larger trees
- Standard C only — no external dependencies
