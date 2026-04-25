
#include <stdio.h>
#include <stdlib.h>

char **array_to_histogram(int *vet, int n) {
    if (!vet || n <= 0) return NULL;

    char **mat = malloc(n * sizeof(char*));
    if (!mat) return NULL;

    for (int i = 0; i < n; i++) {
        mat[i] = malloc(vet[i] * sizeof(char));
        for (int j = 0; j < vet[i]; j++) {
            mat[i][j] = '*';
        }
    }

    return mat;
}

int main() {
    int vet[5] = {3,5,7,2,9};

    char **mat = array_to_histogram(vet, 5);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < vet[i]; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < 5; i++) free(mat[i]);
    free(mat);

    return 0;
}
