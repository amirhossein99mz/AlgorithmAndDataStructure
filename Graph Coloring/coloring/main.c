#include <stdio.h>
#include <stdlib.h>

/*
 * isSafe: checks whether assigning 'color' to vertex v is valid,
 * i.e. no adjacent vertex already holds the same color.
 */
int isSafe(int **graph, int n, int v, int color, int *colors) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && colors[v] == color) return 0;
    }
    return 1;
}

/*
 * solve: backtracking search that tries to color all vertices 0..n-1
 * using at most maxColors colors. Returns 1 on success, 0 on failure.
 */
int solve(int **graph, int n, int v, int maxColors, int *colors) {
    if (v == n) return 1;

    for (int c = 1; c <= maxColors; c++) {
        if (isSafe(graph, n, v, c, colors)) {
            colors[v] = c;
            if (solve(graph, n, v + 1, maxColors, colors)) return 1;
            colors[v] = 0;
        }
    }
    return 0;
}

/*
 * color: entry point. Tries increasing numbers of colors starting from 1
 * until a valid coloring is found. Prints the minimum color count and
 * the color assigned to each vertex.
 */
void color(int **graph, int n) {
    int *colors = calloc(n, sizeof(int));

    for (int m = 1; m <= n; m++) {
        if (solve(graph, n, 0, m, colors)) {
            printf("Maximum colors: %d\n", m);
            for (int i = 0; i < n; i++) printf("%d %d\n", i, colors[i]);
            free(colors);
            return;
        }
    }
    free(colors);
}

int main() {
    /*
     * Example graph (4 vertices A=0, B=1, C=2, D=3):
     *   A - B - C - D - A  (cycle → needs 2 colors)
     *
     * Adjacency matrix:
     *   0 1 0 1
     *   1 0 1 0
     *   0 1 0 1
     *   1 0 1 0
     */
    int n = 4;
    int **graph = malloc(n * sizeof(int *));
    int mat[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    for (int i = 0; i < n; i++) {
        graph[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) graph[i][j] = mat[i][j];
    }

    color(graph, n);

    for (int i = 0; i < n; i++) free(graph[i]);
    free(graph);
    return 0;
}
