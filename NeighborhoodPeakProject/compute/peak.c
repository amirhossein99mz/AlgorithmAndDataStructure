#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_number=-1;

int max(int **mat,int n,int k,int r,int c) {

    int max_rel = mat[r][c];
    for (int i=r-k;i<=r+k;i++) {
        for (int j=c-k;j<=c+k;j++) {
            if (i>=0 && i<n && j>=0 && j<n) {
                if (mat[i][j]>max_rel) max_rel=mat[i][j];
            }
        }
    }
    return max_rel;
}

void local_max(int **mat,int n,int k) {
    int max_rel;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            max_rel = max(mat,n,k,i,j);
            if (max_rel>max_number) max_number=max_rel;
        }
    }

    int row=-1,col=-1;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (mat[i][j]==max_number) row=i,col=j;
        }
    }

    printf("Maximum value is %d in[%d][%d]",max_number,row,col);
}
