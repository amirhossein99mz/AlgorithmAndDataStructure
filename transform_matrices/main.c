#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transform(char *s, char **mat1, char **mat2, int n) {
    int index = 0;

    // Fill mat1 (row-wise)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat1[i][j] = s[index] ? s[index++] : '-';
        }
    }

    // Reset index
    index = 0;

    // Fill mat2 (reverse column-wise from bottom-right)
    for (int j = n - 1; j >= 0; j--) {
        for (int i = n - 1; i >= 0; i--) {
            mat2[i][j] = s[index] ? s[index++] : '-';
        }
    }
}

void print_matrix(char **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    char *s = strdup("helloworld");

    char **mat1 = malloc(n * sizeof(char *));
    char **mat2 = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        mat1[i] = malloc(n * sizeof(char));
        mat2[i] = malloc(n * sizeof(char));
    }

    transform(s, mat1, mat2, n);

    printf("Matrix 1:\n");
    print_matrix(mat1, n);

    printf("\nMatrix 2:\n");
    print_matrix(mat2, n);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(mat1[i]);
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);
    free(s);

    return 0;
}
