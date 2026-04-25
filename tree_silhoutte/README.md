# Tree Silhouette (Boundary Traversal)

## Problem
Print the boundary of a binary tree:
- Root
- Left boundary (excluding leaves)
- All leaves (left to right)
- Right boundary (bottom-up, excluding leaves)

## Approach
1. Print root
2. Traverse left boundary
3. Print all leaves
4. Traverse right boundary using stack (reverse order)

## Complexity
Time: O(n)
Space: O(h) for stack

## Output Example
1 A, 2 B, 3 C, 6 F, 8 H, 9 I, 7 G
