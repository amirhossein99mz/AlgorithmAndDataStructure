# Partition Program README

## Description
This project contains a C program that partitions an array of integers into `k` blocks such that the variance of the sum of each block is minimized. It ensures each block's size differs by at most 1.

## Files
- `partition.c` : Contains the full implementation of the partition algorithm and `main()` example.
- `README.md` : Provides compilation instructions and usage examples.

## Compilation Instructions
To compile the program, use a standard C compiler. Example:

```bash
gcc -o partition partition.c -lm
```

The `-lm` flag links the math library for accurate floating-point operations.

## Usage
Run the compiled executable:

```bash
./partition
```

The program prints the blocks of integers that yield the minimum variance.

## Example
For `vet = {1,2,3,4,5,6,7,8,9,10}` and `k = 3`, the output may be:

```
Minimum variance partition:
Block 1: 1 2 3 4
Block 2: 5 6 7
Block 3: 8 9 10
```

This example partitions the array into three blocks with balanced sums and minimum variance.

## Notes
- Dynamic memory allocation is used internally.
- The algorithm recursively generates all balanced partitions.
- Works for any `n` and `k` where `n >= k >= 1`.
- Modify `vet`, `n`, and `k` in `main()` to test different arrays.