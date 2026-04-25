
# Exercise 11 — Array to Histogram

## Task
Convert an integer array into a 2D array where each row contains '*' repeated vet[i] times.

## Function
char **array_to_histogram(int *vet, int n);

## Idea
- Allocate n rows
- Each row has vet[i] chars
- Fill with '*'

## Example
Input:
[2, 4, 1]

Output:
**
****
*
