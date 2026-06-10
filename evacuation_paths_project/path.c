#include <stdio.h>
#include <stdlib.h>

int isValid(int *path,int len,int src_city,int dst_city,int sum,int budget) {
    if (path[len-1]!=dst_city || path[0]!=src_city || sum> budget)return 0;
    return 1;
}

void dfs(int **m,int n,int u,int budget,int sum,int *visited,int len,int *n_path,int *path,int src_city,int dst_city) {
    visited[u]=1;
    path[len++] = u;

    if (isValid(path,len,src_city,dst_city,sum,budget)) {
        (*n_path)++;
        printf("%d :",*n_path);
        for (int i=0;i<len-1;i++) printf(" %d->",path[i]);
        printf("%d ; ",path[len-1]);
        printf("cost = %d\n",sum);
        visited[u]=0;
        return ;
    }

    for (int v=0;v<n;v++) {
        if (m[u][v] >0 && !visited[v]) {
            dfs(m,n,v,budget,sum+m[u][v],visited,len,n_path,path,src_city,dst_city);
        }
    }
    visited[u]=0;
}

void find_all_paths(int **m, int n, int src_city, int dst_city, int budget) {
    if (!m || !*m)return;

    int n_path=0;
    int *path = malloc(sizeof(int)*n);
    int *visited = calloc(n,sizeof(int));
    if (!path || !visited)return;

    dfs(m,n,src_city,budget,0,visited,0,&n_path,path,src_city,dst_city);

    free(path);
    free(visited);
}

int main(int argc,char **argv) {
    int matrix[4][4] = {
        {0, 10, 0, 30},
        {10, 0, 50, 0},
        {0, 50, 0, 20},
        {30, 0, 20, 0}
    };

    int **mat = malloc( 4 * sizeof(int*));
    if (!mat)return -1;

    for (int i = 0; i < 4; i++) mat[i] = matrix[i];

    find_all_paths(mat,4,0,2,55);

    free(mat);
    return 0;
}
