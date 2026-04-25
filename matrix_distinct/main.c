
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int count;
} Pair;

int find(Pair *arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i].value == val) return i;
    }
    return -1;
}

void cde(int **mat, int r, int c) {
    Pair *arr = malloc(r * c * sizeof(Pair));
    int size = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int idx = find(arr, size, mat[i][j]);
            if (idx == -1) {
                arr[size].value = mat[i][j];
                arr[size].count = 1;
                size++;
            } else {
                arr[idx].count++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d[%d] ", arr[i].value, arr[i].count);
    }
    printf("\n");

    free(arr);
}

int main() {
    int r = 4, c = 3;

    int data[4][3] = {
        {1,2,3},
        {4,2,1},
        {3,5,6},
        {7,3,3}
    };

    int *mat[4];
    for (int i = 0; i < r; i++)
        mat[i] = data[i];

    cde(mat, r, c);

    return 0;
}
