#include <stdio.h>
#include <stdlib.h>

/* ─────────────────────────────────────────────
   Direction vectors for the 8 possible moves
   (horizontal, vertical, diagonal)
   ───────────────────────────────────────────── */
int dx[8] = {1, -1, 1,  0,  1, -1, -1, 0};
int dy[8] = {1, -1, 0,  1, -1,  1,  0, -1};

/* Global trackers for the best path found */
int max_sum  = -1;
int best_len =  0;

/* ─────────────────────────────────────────────
   copy_path – copies `len` steps from src to dst
   Each step stores: [row, col, cell_value]
   ───────────────────────────────────────────── */
void copy_path(int **src, int **dst, int len) {
    for (int i = 0; i < len; i++) {
        dst[i][0] = src[i][0];
        dst[i][1] = src[i][1];
        dst[i][2] = src[i][2];
    }
}

/* ─────────────────────────────────────────────
   dfs – recursive depth-first search with backtracking
   Explores all valid paths from (i,j) to (r-1,c-1)
   and keeps track of the path with the maximum sum.
   ───────────────────────────────────────────── */
void dfs(int **mat, int r, int c, int f,
         int i, int j, int index,
         int **sol, int **best,
         int sum, int **visited) {

    if (i < 0 || j < 0 || i >= r || j >= c) return;
    if (visited[i][j]) return;

    sol[index][0] = i;
    sol[index][1] = j;
    sol[index][2] = mat[i][j];
    sum += mat[i][j];
    visited[i][j] = 1;
    index++;

    if (i == r - 1 && j == c - 1) {
        if (sum > max_sum) {
            max_sum  = sum;
            best_len = index;
            copy_path(sol, best, index);
        } else if (sum == max_sum) {
            if ((!f && index < best_len) || (f && index > best_len)) {
                best_len = index;
                copy_path(sol, best, index);
            }
            visited[i][j] = 0;
            return;
        }
    }

    for (int d = 0; d < 8; d++) {
        dfs(mat, r, c, f, i + dx[d], j + dy[d], index, sol, best, sum, visited);
    }

    visited[i][j] = 0;   /* backtrack */
}

/* ─────────────────────────────────────────────
   mat_visit – entry point
   Allocates helper structures and launches DFS,
   then prints the best path found.
   ───────────────────────────────────────────── */
void mat_visit(int **mat, int r, int c, int f) {
    int **sol = malloc(r * c * sizeof(int *));
    if (!sol) return;
    for (int i = 0; i < r * c; i++) {
        sol[i] = malloc(3 * sizeof(int));
        if (!sol[i]) return;
    }

    int **best = malloc(r * c * sizeof(int *));
    if (!best) return;
    for (int i = 0; i < r * c; i++) {
        best[i] = malloc(3 * sizeof(int));
        if (!best[i]) return;
    }

    int **visited = calloc(r * c, sizeof(int *));
    if (!visited) return;

    dfs(mat, r, c, f, 0, 0, 0, sol, best, 0, visited);

    for (int i = 0; i < best_len - 1; i++) {
        printf("[%d,%d]%d - ", best[i][0], best[i][1], best[i][2]);
    }
    printf("[%d,%d]%d", best[best_len - 1][0], best[best_len - 1][1], best[best_len - 1][2]);
    printf(" - sum = %d\n", max_sum);

    /* free allocations */
    for (int i = 0; i < r * c; i++) { free(sol[i]); free(best[i]); }
    free(sol); free(best); free(visited);
}

/* ─────────────────────────────────────────────
   main – example from the exercise (3×3 matrix)
   ───────────────────────────────────────────── */
int main(void) {
    int r = 3, c = 3;

    /* allocate matrix */
    int **mat = malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        mat[i] = malloc(c * sizeof(int));

    /* fill with example values */
    int values[3][3] = {
        {1, 2, 7},
        {9, 3, 7},
        {4, 1, 4}
    };
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            mat[i][j] = values[i][j];

    printf("f=0 (shortest best path):\n");
    mat_visit(mat, r, c, 0);

    /* reset globals for second run */
    max_sum  = -1;
    best_len =  0;

    printf("\nf=1 (longest best path):\n");
    mat_visit(mat, r, c, 1);

    for (int i = 0; i < r; i++) free(mat[i]);
    free(mat);
    return 0;
}
