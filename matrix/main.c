
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int a[][100], int k) {
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void check(int **m, int n, int k) {

    int max_sum = -1000000000;
    int min_sum =  1000000000;

    int max_mat[100][100];
    int min_mat[100][100];

    for(int i=0;i<=n-k;i++){
        for(int j=0;j<=n-k;j++){

            int sum = 0;
            int temp[100][100];

            for(int ii=0; ii<k; ii++){
                for(int jj=0; jj<k; jj++){
                    temp[ii][jj] = m[i+ii][j+jj];
                    sum += temp[ii][jj];
                }
            }

            if(sum > max_sum){
                max_sum = sum;
                for(int x=0;x<k;x++)
                    for(int y=0;y<k;y++)
                        max_mat[x][y] = temp[x][y];
            }

            if(sum < min_sum){
                min_sum = sum;
                for(int x=0;x<k;x++)
                    for(int y=0;y<k;y++)
                        min_mat[x][y] = temp[x][y];
            }
        }
    }

    printf("Max sum submatrix:\n");
    printMatrix(max_mat, k);

    printf("Min sum submatrix:\n");
    printMatrix(min_mat, k);
}

int main() {

    int n = 6, k = 3;

    int data[6][6] = {
        {0,1,0,1,0,1},
        {1,0,1,0,1,0},
        {0,1,0,0,0,1},
        {1,0,1,0,1,0},
        {0,1,0,0,0,0},
        {3,0,1,0,2,0}
    };

    int *m[6];
    for(int i=0;i<n;i++) m[i] = data[i];

    check(m,n,k);

    return 0;
}
