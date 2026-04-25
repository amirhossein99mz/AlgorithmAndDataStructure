#include <stdio.h>

#define N 8

int dx[8]={-1,-1,1,1,-2,-2,2,2};
int dy[8]={-2,2,-2,2,-1,1,-1,1};

void knight(int mat[N][N],int *r,int *c) {

    int max=0;
    for (int i=0;i<*r;i++) {
        for (int j=0;j<*c;j++) {
            if (!mat[i][j]) {
                int sum=0;
                for (int d=0;d<8;d++) {
                    int ni = i+dx[d];
                    int nj = j+dy[d];
                    sum += ni >= 0 && ni < N && nj >= 0 && nj < N ? mat[ni][nj] : 0;
                }
                if (sum>max)max=sum;
            }
        }
    }
}
