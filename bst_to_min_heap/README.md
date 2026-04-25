# Convert BST to Min Heap

## Idea
1. Perform inorder traversal → get sorted values
2. Reassign values using level-order traversal (BFS)

## Why it works
- Inorder gives sorted sequence
- Level-order assignment ensures heap property

## Complexity
Time: O(n)
Space: O(n)
