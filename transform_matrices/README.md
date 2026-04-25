# Transform String into Two Matrices

## Problem
Given a string and two n x n matrices:
- Fill mat1 row-wise (left to right, top to bottom)
- Fill mat2 in reverse column order (bottom to top, right to left)
- Fill remaining cells with '-'

## Approach
1. Use an index to traverse the string
2. Fill mat1 normally
3. Reset index
4. Fill mat2 using reverse traversal

## Complexity
Time: O(n^2)
Space: O(1) extra (excluding matrices)

## Example
Input: "helloworld", n = 4

mat1:
h e l l
o w o r
l d - -
- - - -

mat2:
- - r l
- - o l
- d w e
- l o h
