#include <stdio.h>
#include <stdlib.h>

/*
 * compress: removes duplicate rows first, then duplicate columns from a
 * char** matrix in-place. Updates *r and *c to reflect the new dimensions.
 * Returns the modified matrix.
 */
char **compress(char **mat, int *r, int *c) {

    // 1. Remove duplicate rows
    for (int i = 0; i < *r - 1; i++) {
        for (int j = i + 1; j < *r;) {
            int equal = 1;
            for (int k = 0; k < *c; k++) {
                if (mat[i][k] != mat[j][k]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) {
                for (int k = j; k < *r - 1; k++) mat[k] = mat[k + 1];
                (*r)--;
            } else j++;
        }
    }

    // 2. Remove duplicate columns
    for (int i = 0; i < *c - 1; i++) {
        for (int j = i + 1; j < *c;) {
            int equal = 1;
            for (int k = 0; k < *r; k++) {
                if (mat[k][i] != mat[k][j]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) {
                for (int row = 0; row < *r; row++) {
                    for (int col = j; col < *c - 1; col++) {
                        mat[row][col] = mat[row][col + 1];
                    }
                }
                (*c)--;
            } else j++;
        }
    }

    return mat;
}

// Helper: print the matrix
void printMatrix(char **mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r = 5, c = 6;

    // Allocate rows
    char **mat = malloc(r * sizeof(char *));
    char rows[5][6] = {
        {'1','2','3','4','5','1'},
        {'1','2','3','4','5','1'},
        {'6','7','8','9','0','6'},
        {'6','7','8','9','0','6'},
        {'1','3','5','7','9','1'}
    };
    for (int i = 0; i < r; i++) {
        mat[i] = malloc(c * sizeof(char));
        for (int j = 0; j < c; j++) mat[i][j] = rows[i][j];
    }

    printf("Original matrix (%d x %d):\n", r, c);
    printMatrix(mat, r, c);

    mat = compress(mat, &r, &c);

    printf("\nCompressed matrix (%d x %d):\n", r, c);
    printMatrix(mat, r, c);

    for (int i = 0; i < r; i++) free(mat[i]);
    free(mat);
    return 0;
}
