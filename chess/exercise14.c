#include <stdio.h>

#define N 8

int dx[8]={-1,-1,1,1,-2,-2,2,2};
int dy[8]={-2,2,-2,2,-1,1,-1,1};

void knight(int mat[N][N],int *r,int *c) {

    int max_sum=-1;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {

            if (mat[i][j]==0) {

                int sum=0;

                for (int d=0;d<8;d++) {

                    int x=i+dx[d];
                    int y=j+dy[d];

                    if (x>=0 && x<N && y>=0 && y<N)
                        sum+=mat[x][y];
                }

                if (sum>max_sum) {
                    max_sum=sum;
                    *r=i;
                    *c=j;
                }
            }
        }
    }
}

int main() {

    int mat[N][N]={
        {0,1,2,0,3,0,1,0},
        {2,0,1,4,0,2,0,1},
        {0,3,0,1,2,0,4,0},
        {1,0,2,0,3,1,0,2},
        {0,2,1,0,0,4,2,0},
        {3,0,0,2,1,0,3,1},
        {0,1,4,0,2,1,0,2},
        {2,0,1,3,0,2,1,0}
    };

    int r,c;

    knight(mat,&r,&c);

    printf("Best position: [%d,%d]\n",r,c);

    return 0;
}
