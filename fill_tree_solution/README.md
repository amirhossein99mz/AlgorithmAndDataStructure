# Fill Binary Tree (Level-order insertion)

## Problem
Insert a string into a binary tree while maintaining completeness:
- Fill levels from left to right
- Insert at the first missing position

## Approach
We use BFS (queue):
1. Traverse tree level by level
2. First node missing left → insert there
3. Else if missing right → insert there
4. Otherwise continue

## Complexity
- Time: O(n)
- Space: O(n)

## Notes
- This behaves like a heap insertion (but without ordering)
- Queue implemented using linked list
