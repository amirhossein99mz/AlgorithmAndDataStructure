
# Exercise 13 — Longest Weight Path (Alternating Colors)

## Task
Given a directed acyclic graph (DAG) with weights and vertex colors (WHITE/BLACK),
find the path with the maximum total weight such that adjacent vertices have different colors.

## Function
void longest_weight_path(int **g, int *color, char **vertex_id, int n);

## Idea
- Use DFS from every node
- Only follow edges to nodes with different color
- Track total weight
- Keep best path

## Example
Vertices: A, B, C  
Colors: WHITE, BLACK, WHITE  

Edges:
A → B (3)  
B → C (5)  

Valid path: A → B → C  
Total weight: 8

Output:
A B C
