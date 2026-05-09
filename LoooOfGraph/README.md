# Loop of Graph - DFS Solution

## Description
This program finds and prints all loops (cycles) of size `k`
in a directed graph represented by an adjacency matrix.

The algorithm uses Depth First Search (DFS) and backtracking.

## Functions

### printCycle
Prints the vertices of a detected cycle.

### dfs
Performs recursive DFS traversal:
- marks visited vertices
- stores current path
- checks if a cycle of size `k` exists
- backtracks after recursion

### loop
Initializes arrays and starts DFS from every vertex.

## Example Output

For the given graph and `k = 3`:

0 2 3
2 3 0
3 0 2

## Compilation

gcc loopOfGraph.c -o loop

## Run

./loop
