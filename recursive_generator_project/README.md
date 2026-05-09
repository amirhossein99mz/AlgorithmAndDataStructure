# Recursive Number Generator in C

This program generates all decimal numbers of n digits such that:

- Digits in positions 0,2,4,... are even
- Digits in positions 1,3,5,... are odd
- Sum of even-position digits equals sum of odd-position digits

Example valid numbers for n=4:

- 1430
- 3652
- 5676

## Compile

gcc recursive_generator.c -o app

## Run

./app

The output will be written into:

output.txt
