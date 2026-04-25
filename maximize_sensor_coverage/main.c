#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int min;
int best[MAX];

int is_covered(int **grid, int r, int c, int *sensor, int n) {
    int *covered = calloc(c, sizeof(int));

    for (int i = 0; i < n; i++) {
        int row = sensor[i];
        for (int j = 0; j < c; j++) {
            if (grid[row][j]) covered[j] = 1;
        }
    }

    for (int i = 0; i < c; i++) {
        if (!covered[i]) {
            free(covered);
            return 0;
        }
    }

    free(covered);
    return 1;
}

void backtrack(int **grid, int r, int c, int *sensors, int pos, int start, int k) {
    if (pos == k) {
        if (is_covered(grid, r, c, sensors, k)) {
            if (k < min) {
                min = k;
                for (int i = 0; i < k; i++) best[i] = sensors[i];
            }
        }
        return;
    }

    for (int i = start; i < r; i++) {
        sensors[pos] = i;
        backtrack(grid, r, c, sensors, pos + 1, i + 1, k);
    }
}

int maximize_sensor_coverage(int **grid, int r, int c, int *sensors, int *count) {
    int temp[MAX];
    min = MAX;

    for (int k = 1; k <= r; k++) {
        backtrack(grid, r, c, temp, 0, 0, k);
        if (min != MAX) break;
    }

    if (min == MAX) return 0;

    *count = min;
    for (int i = 0; i < min; i++) sensors[i] = best[i];

    return 1;
}

// simple test
int main() {
    int r = 5, c = 7;

    int data[5][7] = {
        {1,1,0,0,0,0,1},
        {0,0,1,1,1,0,0},
        {1,0,0,1,0,1,1},
        {0,1,0,1,0,1,0},
        {0,0,1,1,1,1,1}
    };

    int **grid = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        grid[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) grid[i][j] = data[i][j];
    }

    int sensors[MAX];
    int count;

    if (maximize_sensor_coverage(grid, r, c, sensors, &count)) {
        printf("Solution found with %d sensors:\n", count);
        for (int i = 0; i < count; i++) {
            printf("%d ", sensors[i]);
        }
        printf("\n");
    } else {
        printf("No solution\n");
    }

    for (int i = 0; i < r; i++) free(grid[i]);
    free(grid);

    return 0;
}
