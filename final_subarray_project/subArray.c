#include <stdio.h>
#include <stdlib.h>

void check(int **m,int n,int k) {

    int max_sum = -1;
    int min_sum = 1000;

    int mat_max_sum[k][k];
    int mat_min_sum[k][k];

    for (int i=0;i<=n-k;i++) {

        for (int j=0;j<=n-k;j++) {

            int sum = 0;

            for (int ii=i; ii<i+k; ii++) {

                for (int jj=j; jj<j+k; jj++) {

                    sum += m[ii][jj];
                }
            }

            if (sum > max_sum) {

                max_sum = sum;

                int row = 0;

                for (int ii=i; ii<i+k; ii++,row++) {

                    int col = 0;

                    for (int jj=j; jj<j+k; jj++,col++) {

                        mat_max_sum[row][col] = m[ii][jj];
                    }
                }
            }

            if (sum < min_sum) {

                min_sum = sum;

                int row = 0;

                for (int ii=i; ii<i+k; ii++,row++) {

                    int col = 0;

                    for (int jj=j; jj<j+k; jj++,col++) {

                        mat_min_sum[row][col] = m[ii][jj];
                    }
                }
            }
        }
    }

    printf("Max sum is %d\n",max_sum);

    for (int i=0;i<k;i++) {

        for (int j=0;j<k;j++) {

            printf("%d ",mat_max_sum[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    printf("Min sum is %d\n",min_sum);

    for (int i=0;i<k;i++) {

        for (int j=0;j<k;j++) {

            printf("%d ",mat_min_sum[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int mat[6][6] = {
        {0,1,0,1,0,1},
        {1,0,1,0,1,0},
        {0,1,0,0,0,1},
        {1,0,1,0,1,0},
        {0,1,0,0,0,0},
        {3,0,1,0,2,0}
    };

    int **mat2 = malloc(6*sizeof(int*));

    if (!mat2) return 0;

    for (int i=0;i<6;i++) {

        mat2[i] = mat[i];
    }

    check(mat2,6,3);

    free(mat2);

    return 0;
}
