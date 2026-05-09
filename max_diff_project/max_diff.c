#include <stdio.h>
#include <stdlib.h>

void max_diff(int **mat,int r,int c) {

    int max_diff = 0;

    int final_row=-1;
    int final_col=-1;

    for (int i=0;i<r;i++) {

        for (int j=0;j<c;j++) {

            int min=mat[i][j];
            int max=mat[i][j];

            int row=i,col=j;

            // going right top
            while (--row>=0 && ++col<c) {

                if (mat[row][col]>max)
                    max=mat[row][col];

                if (mat[row][col]<min)
                    min=mat[row][col];
            }

            row=i;
            col=j;

            // going right bottom
            while (++row<r && ++col<c) {

                if (mat[row][col]>max)
                    max=mat[row][col];

                if (mat[row][col]<min)
                    min=mat[row][col];
            }

            row=i;
            col=j;

            // going left top
            while (--row>=0 && --col>=0) {

                if (mat[row][col]>max)
                    max=mat[row][col];

                if (mat[row][col]<min)
                    min=mat[row][col];
            }

            row=i;
            col=j;

            // going left bottom
            while (++row<r && --col>=0) {

                if (mat[row][col]>max)
                    max=mat[row][col];

                if (mat[row][col]<min)
                    min=mat[row][col];
            }

            int diff = max - min;

            if (diff>max_diff) {

                max_diff = diff;
                final_row = i;
                final_col = j;
            }
        }
    }

    printf("Maximum difference is %d for element at indices [%d,%d]",
           max_diff,final_row,final_col);
}

int main() {

    int r = 4;
    int c = 5;

    int matrix[4][5] = {
        {0,-2,1,0,0},
        {0,0,1,0,2},
        {0,0,0,1,1},
        {1,0,5,0,0}
    };

    int **mat = malloc(r*sizeof(int*));

    if (!mat) return 0;

    for (int i=0;i<r;i++) {
        mat[i] = matrix[i];
    }

    max_diff(mat,r,c);

    free(mat);

    return 0;
}
