# Square Submatrix Program

## Goal

Write a C function that checks every `k x k` part of a square matrix.

Function:

```c
void check(int **m, int n, int k);
```

The program must:
- find the submatrix with the biggest sum
- find the submatrix with the smallest sum
- print both results

---

## Example

Matrix:

```text
1 2 0 1
3 4 1 0
2 1 5 2
0 1 2 3
```

with:

```text
k = 2
```

Largest sum block:

```text
1 5
2 3
```

Smallest sum block:

```text
0 1
1 0
```

---

## Compile

```bash
gcc subArray.c -o app
```

## Run

```bash
./app
```
