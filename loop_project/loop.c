#include <stdio.h>
#include <stdlib.h>

void dfss(int **mat, int u, int n, int k, int *visited, int len, int *path, int src) {

    visited[u] = 1;
    path[len++] = u;

    if (len == k) {
        if (mat[u][src]) {
            for (int i = 0; i < len; i++)
                printf("%d ", path[i]);
            printf("\n");
        }
        visited[u] = 0;
        return;
    }

    for (int v = 0; v < n; v++) {
        if (mat[u][v] && !visited[v]) {
            dfss(mat, v, n, k, visited, len, path, src);
        }
    }

    visited[u] = 0;
}

void loop(int **mat, int n, int k) {

    int *visited = calloc(n, sizeof(int));
    int *path = malloc(n * sizeof(int));

    if (!visited || !path) {
        free(visited);
        free(path);
        return;
    }

    for (int u = 0; u < n; u++) {
        dfss(mat, u, n, k, visited, 0, path, u);
    }

    free(visited);
    free(path);
}

int main() {
    int arr[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    int **arr2 = malloc(sizeof(int *) * 4);
    if (!arr2) return 1;

    for (int i = 0; i < 4; i++)
        arr2[i] = arr[i];

    loop(arr2, 4, 3);

    free(arr2);

    return 0;
}
