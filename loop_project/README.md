# Loop Detection in a Directed Graph

This small C program prints all loops of exactly `k` vertices in a directed graph represented by an adjacency matrix.

## Files

- `loop.c`: C source code containing the DFS-based loop search.
- `README.md`: short explanation and compilation instructions.

## How it works

The graph is stored as an adjacency matrix `mat`, where:

- `mat[i][j] = 1` means there is an edge from vertex `i` to vertex `j`.
- `mat[i][j] = 0` means there is no edge.

The function:

```c
void loop(int **mat, int n, int k);
```

starts a DFS from every vertex and prints paths of exactly `k` vertices that return to the starting vertex.

## Example graph

The example matrix in `main` is:

```text
0 1 1 0
0 0 1 0
0 0 0 1
1 0 0 0
```

With `k = 3`, the output is:

```text
0 2 3
2 3 0
3 0 2
```

## Compile and run

```bash
gcc loop.c -o loop
./loop
```
