#include <stdio.h>
#include <stdlib.h>

void local_max(int **mat,int n,int k);

int main() {
    int mat[4][4]={{3,2,1,1},{2,4,1,1},{0,1,0,0},{1,0,1,2}};

    int **matrix = malloc(4*sizeof(int *));
    if (!matrix)return -1;

    for (int i=0;i<4;i++) {
        matrix[i] = mat[i];
    }

    local_max(matrix,4,1);

    free(matrix);

    return 1;
}
