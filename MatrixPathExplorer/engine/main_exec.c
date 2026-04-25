#include <stdio.h>
#include <stdlib.h>

void mat_visit(int **mat,int r,int c,int f);

int main() {
    int r = 2, c = 2;

    int **mat = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        mat[i] = malloc(c * sizeof(int));
    }

    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;

    mat_visit(mat, r, c, 0);

    for (int i = 0; i < r; i++) free(mat[i]);
    free(mat);

    return 0;
}
