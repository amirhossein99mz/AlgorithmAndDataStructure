
# Exercise 13 — Acronym Generator

## Task
Given n strings, build all possible acronyms by picking one character from each string.

Keep only acronyms where:
- letters and digits alternate
- all letters are either lowercase OR uppercase (not mixed)

## Function
void acronym(char *nameI, char *nameO);

## Idea
- Use recursion (backtracking)
- Build string character by character
- Validate before saving

## Example
Input:
3
A1
Xy2
123B

Output (example):
A2B
1X1
1y2
