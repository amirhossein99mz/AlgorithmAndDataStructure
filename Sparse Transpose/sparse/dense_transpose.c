#include <stdio.h>
#include <stdlib.h>

/*
 * transpose: computes the transpose of a dense integer matrix.
 * Allocates a new col x row matrix and writes mat[i][j] -> result[j][i].
 */
void transpose(int **mat, int row, int col, int ***transpose_mat) {
    *transpose_mat = calloc(col, sizeof(int *));

    for (int i = 0; i < col; i++)
        (*transpose_mat)[i] = calloc(row, sizeof(int));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            (*transpose_mat)[j][i] = mat[i][j];
        }
    }
}
