
#include <stdio.h>
#include <stdlib.h>

int max_diff(int **mat, int r, int c) {

    int max_difference = -1000000000;
    int best_i = 0, best_j = 0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){

            int min = mat[i][j];
            int max = mat[i][j];

            // explore 4 diagonal directions INCLUDING the cell itself
            int dirs[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};

            for(int d=0; d<4; d++){
                int x = i;
                int y = j;

                while(x>=0 && x<r && y>=0 && y<c){
                    if(mat[x][y] > max) max = mat[x][y];
                    if(mat[x][y] < min) min = mat[x][y];

                    x += dirs[d][0];
                    y += dirs[d][1];
                }
            }

            if(max - min > max_difference){
                max_difference = max - min;
                best_i = i;
                best_j = j;
            }
        }
    }

    printf("(%d, %d)\n", best_i, best_j);
    return max_difference;
}

int main() {

    int r = 4, c = 5;

    int data[4][5] = {
        {0,-2,1,0,0},
        {0,0,1,0,2},
        {0,0,0,1,1},
        {1,0,5,0,0}
    };

    int *mat[4];
    for(int i=0;i<r;i++) mat[i] = data[i];

    int res = max_diff(mat, r, c);
    printf("Max difference = %d\n", res);

    return 0;
}
