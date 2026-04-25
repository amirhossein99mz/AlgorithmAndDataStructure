#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ──────────────────────────────────────────────
 * Graph: adjacency matrix representation
 * ────────────────────────────────────────────── */
typedef struct {
    int  nv;
    int **adjMatrix;
} Graph;

Graph *createGraph(int nv) {
    Graph *graph = malloc(sizeof(Graph));
    if (!graph) return NULL;

    graph->nv = nv;
    graph->adjMatrix = malloc(nv * sizeof(int *));
    if (graph->adjMatrix == NULL) {
        free(graph);
        return NULL;
    }
    for (int i = 0; i < nv; i++)
        graph->adjMatrix[i] = calloc(nv, sizeof(int));
    return graph;
}

/* ──────────────────────────────────────────────
 * printGraph: prints one cycle path
 * ────────────────────────────────────────────── */
void printGraph(int *path, int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

/* ──────────────────────────────────────────────
 * cycle: recursive DFS to find cycles of length k
 *   mat     - adjacency matrix
 *   n       - number of vertices
 *   k       - target cycle length
 *   depth   - current recursion depth
 *   s       - start node
 *   u       - current node
 *   visited - tracks visited nodes
 *   path    - stores current path
 * ────────────────────────────────────────────── */
void cycle(int **mat, int n, int k, int depth, int s, int u,
           int *visited, int *path) {

    visited[u]    = 1;
    path[depth]   = u;

    // Base case: reached desired depth, check edge back to start
    if (depth == k - 1) {
        if (mat[u][s]) {
            printGraph(path, k);
        }
        visited[u] = 0;
        return;
    }

    // Recurse on unvisited neighbours
    for (int i = 0; i < n; i++) {
        if (mat[u][i] && !visited[i]) {
            cycle(mat, n, k, depth + 1, s, i, visited, path);
        }
    }

    visited[u] = 0;
}

/* ──────────────────────────────────────────────
 * loop: entry point — tries every node as start
 * ────────────────────────────────────────────── */
void loop(int **mat, int n, int k) {
    int *visited = calloc(n, sizeof(int));
    int *path    = calloc(k, sizeof(int));

    for (int i = 0; i < n; i++) {
        cycle(mat, n, k, 0, i, i, visited, path);
    }

    free(visited);
    free(path);
}

int main() {
    // Demo: 4-node directed graph
    int nv = 4;
    Graph *g = createGraph(nv);

    // Add edges: 0->1, 1->2, 2->0, 2->3, 3->1
    g->adjMatrix[0][1] = 1;
    g->adjMatrix[1][2] = 1;
    g->adjMatrix[2][0] = 1;
    g->adjMatrix[2][3] = 1;
    g->adjMatrix[3][1] = 1;

    int k = 3;
    printf("All cycles of length %d:\n", k);
    loop(g->adjMatrix, nv, k);

    // Free memory
    for (int i = 0; i < nv; i++) free(g->adjMatrix[i]);
    free(g->adjMatrix);
    free(g);
    return 0;
}
