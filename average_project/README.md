# Average of Diagonals Matrix Program

## Description

This program computes, for every element of the input matrix, the average of all elements belonging to the primary and secondary diagonals centered on that element.

The result is stored in the output matrix `matO`.

## Logic

For each element `[i][j]`, the program explores:

- top-right diagonal
- bottom-right diagonal
- top-left diagonal
- bottom-left diagonal

The values are summed together with the central element itself.

average = sum / number_of_elements

## Files

- average.c
- README.md

## Compile

gcc average.c -o average

## Run

./average
