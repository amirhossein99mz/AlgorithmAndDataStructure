#include <stdio.h>
#include <stdlib.h>

void dfs(int **map, int r, int c, int max_time, int *n_routes,int i,int j,int sum,int **indices,int len) {

    if (i>=r || j>=c || i<0 || j<0 || !map[i][j] || sum >max_time) return;

    sum += map[i][j];

    indices[len][0] = i;
    indices[len][1] = j;
    len++;

    if (i==r-1 && j==c-1) {
        (*n_routes)++;
        printf("Route %d: ",*n_routes);
        for (int k=0; k<len-1; k++)printf("[%d,%d] -> ",indices[k][0],indices[k][1]);
        printf("[%d,%d] ; ",indices[len-1][0],indices[len-1][1]);
        printf("time = %d\n",sum);
        return;
    }
    dfs(map,r,c,max_time, n_routes,i,j+1,sum,indices,len);
    dfs(map,r,c,max_time, n_routes,i+1,j,sum,indices,len);
}

int evacuation_routes(int **map, int r, int c, int max_time, int *n_routes) {
    if (!map || !*map)return -1;
    int sum =0;

    int **indices = malloc(sizeof(int*) * r * c);
    if (!indices) return -1;

    for (int i = 0; i < r*c; i++) {
        indices[i] = malloc(sizeof(int) * 2);
        if (!indices[i]) return -1;
    }
    *n_routes = 0;
    int len=0;
    dfs(map,r,c,max_time, n_routes,0,0,sum,indices,len);

    if (!*n_routes)return 0;
    return 1;

}

int main(int argc,char **argv) {
    int mat[3][4]={{2,3,1,4},{1,0,2,1},{3,2,1,2}};

    int **map = malloc(sizeof(int*)*3);
    for (int i=0;i<3;i++) map[i]= mat[i];
    int n_routes = 0;
    evacuation_routes(map,3,4,13,&n_routes);

    return 0;
}
