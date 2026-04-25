#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_sum=-1;
int max_len=10000;

int dx[8]={0,0,-1,1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};

void dfs(int **mat,int r,int c,int f,int i,int j,int **result,int sum,int index,int len) {

    if (i>=r || j>=c || i<0 || j<0)return;

    result[index][0]=i;
    result[index][1]=j;
    result[index][2]=mat[i][j];

    len++;
    sum += mat[i][j];
    index++;

    if (i==r-1 && j==c-1) {
        if (sum>max_sum)max_sum=sum, max_len=len;

        else if (sum==max_sum) {
            if (!f && len<max_len)max_len=len;
            if (f && len>max_len)max_len=len;
        }
        return;
    }

    for (int d=0;d<8;d++)dfs(mat,r,c,f,i+dx[d],j+dy[d],result,sum,index,len);

    for (int k=0;k<r*c;k++) {
        printf("[%d,%d]%d-", result[k][0],result[k][1],result[k][2]);
    }
}

void mat_visit(int **mat,int r,int c,int f) {
    int **result;
    result = (int**)malloc(r*c*sizeof(int*));
    for (int i=0;i<r;i++)result[i] = (int*)malloc(3*sizeof(int));

    dfs(mat,r,c,f,0,0,result,0,0,0);

    for (int i=0;i<r;i++)free(result[i]);
    free(result);
}
