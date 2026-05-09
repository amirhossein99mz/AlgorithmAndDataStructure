#include <stdio.h>
#include <stdlib.h>

void printCycle(int *path,int n) {
    for (int i=0;i<n;i++) {
        printf("%d ",path[i]);
    }
    printf("\n");
}

void dfs(int **mat,int n,int k,int *path,int *visited,int depth,int u,int v) {

    visited[u]=1;
    path[depth]=u;

    if (depth==k-1) {

        if (mat[u][v])
            printCycle(path,k);

        visited[u]=0;
        return;
    }

    for (int i=0;i<n;i++) {

        if (mat[u][i] && !visited[i]) {
            dfs(mat,n,k,path,visited,depth+1,i,v);
        }
    }

    visited[u]=0;
}

void loop(int **mat,int n,int k) {

    int *path = calloc(n,sizeof(int));
    int *visited = calloc(n,sizeof(int));

    if (!path || !visited)
        return;

    for (int i=0;i<n;i++) {
        dfs(mat,n,k,path,visited,0,i,i);
    }

    free(path);
    free(visited);
}

int main() {

    int mat[4][4] = {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,1},
        {1,0,0,0}
    };

    int **matt = malloc(4*sizeof(int*));

    if (!matt)
        return 0;

    for (int i=0;i<4;i++) {
        matt[i] = mat[i];
    }

    loop(matt,4,3);

    free(matt);

    return 0;
}
