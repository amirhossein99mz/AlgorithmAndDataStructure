
# Exercise 12 — Common Strings in BSTs

## Task
You are given N Binary Search Trees (BSTs).  
Each node stores a string.

Write a function that prints all strings that appear in **every BST**.

## Function
void display_common(node_t *root[N]);

## Idea (simple)
- Traverse the first BST
- For each string, check if it exists in all other BSTs
- Print it if yes

## Example
Tree1: apple, banana, cat  
Tree2: banana, cat, dog  
Tree3: banana, cat, egg  

Output:
banana
cat
