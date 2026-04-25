
# Exercise 12 — File to List of Lists

## Task
Read a file where each row has:
string count numbers...

Group rows by string:
- Each string appears once (main list)
- Numbers are stored in a secondary list
- No duplicate numbers

## Function
list1_t *file_to_list_of_lists(char *name);

## Idea
- For each line:
  - find or create string node
  - insert numbers into its list (unique only)

## Example
Input:
alice 2 10 20
alice 2 20 30

Output:
alice -> {10,20,30}
