# string_to_fifo.c

This project contains a C program with two parts:

1. Sparse matrix list structures and transpose helpers.
2. `string_to_fifo`, which reads one line from a file and separates consecutive alphabetic parts and digit parts into two FIFO linked lists.

## Main idea

The function:

```c
void string_to_fifo(char *s, node_t **letter, node_t **digit);
```

receives a file name `s` and creates two linked lists:

- `letter`: stores alphabetic substrings.
- `digit`: stores numeric substrings.

Example input line:

```text
abc123def45ghi6
```

Output:

```text
Letters FIFO: abc def ghi
Digits FIFO: 123 45 6
```

## Compile

```bash
gcc string_to_fifo.c -o string_to_fifo
```

## Run

```bash
./string_to_fifo
```

The program creates a small `input.txt` file automatically for testing.
