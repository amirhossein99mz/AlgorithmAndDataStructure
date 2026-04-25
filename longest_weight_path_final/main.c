
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define BLACK 1

int best_weight = 0;
int best_path[100];
int best_len = 0;

void dfs(int **g, int *color, char **vertex_id, int n,
         int u, int w, int *path, int len, int prev_color) {

    path[len++] = u;

    if (w > best_weight) {
        best_weight = w;
        best_len = len;
        for (int i = 0; i < len; i++)
            best_path[i] = path[i];
    }

    for (int v = 0; v < n; v++) {
        if (g[u][v] > 0 && color[v] != prev_color) {
            dfs(g, color, vertex_id, n, v,
                w + g[u][v], path, len, color[v]);
        }
    }
}

void longest_weight_path(int **g, int *color, char **vertex_id, int n) {

    int path[100];

    for (int i = 0; i < n; i++) {
        dfs(g, color, vertex_id, n, i, 0, path, 0, color[i]);
    }

    for (int i = 0; i < best_len; i++) {
        printf("%s ", vertex_id[best_path[i]]);
    }
    printf("\n");
}
