
# Exercise 11 — Reorder String

## Task
Reorder characters of a string using an index array.

## Function
char *reorder_string(char *s1, int *v);

## Rules
- Create new string same size
- Place s1[i] at position v[i]
- Validate indices (0 to n-1, no duplicates)

## Example
Input:
s1 = "abc"
v = {2,0,1}

Output:
"bca"
