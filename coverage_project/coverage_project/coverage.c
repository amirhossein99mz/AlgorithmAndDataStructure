#include <stdio.h>
#include <stdlib.h>

int isCovered(int **grid, int r, int c, int *sensor, int k) {
    int *columns = calloc(c, sizeof(int));
    if (!columns) return 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < c; j++) {
            columns[j] += grid[sensor[i]][j];
        }
    }

    for (int i = 0; i < c; i++) {
        if (!columns[i]) {
            free(columns);
            return 0;
        }
    }

    free(columns);
    return 1;
}

void simple_arrangement(int **grid, int r, int c, int *sensor, int *best,
                        int *count, int pos, int *mark, int *min) {

    if (pos > 0) {
        if (isCovered(grid, r, c, sensor, pos)) {
            if (pos < *min) {
                *min = pos;
                *count = pos;

                for (int i = 0; i < pos; i++)
                    best[i] = sensor[i];
            }
        }
    }

    if (pos == r)
        return;

    for (int i = 0; i < r; i++) {
        if (!mark[i]) {
            mark[i] = 1;
            sensor[pos] = i;

            simple_arrangement(grid, r, c, sensor, best, count, pos + 1, mark, min);

            mark[i] = 0;
        }
    }
}

int maximize_sensor_coverage(int **grid, int r, int c, int *sensor, int *count) {

    int *mark = calloc(r, sizeof(int));
    int *best = malloc(r * sizeof(int));

    if (!mark || !best) return -1;

    int min = r + 1;

    simple_arrangement(grid, r, c, sensor, best, count, 0, mark, &min);

    if (min <= r) {
        for (int i = 0; i < min; i++) {
            sensor[i] = best[i];
        }

        free(mark);
        free(best);

        return 1;
    }

    free(mark);
    free(best);

    return 0;
}

int main(int argc, char **argv) {
    int matrix[5][7] = {
        {1, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 1, 1},
        {0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 1}
    };

    int **grid = malloc(sizeof(int *) * 5);
    if (!grid) return -1;

    for (int i = 0; i < 5; i++)
        grid[i] = matrix[i];

    int *sensor = malloc(sizeof(int) * 5);
    if (!sensor) {
        free(grid);
        return -1;
    }

    int count = 0;
    int result = maximize_sensor_coverage(grid, 5, 7, sensor, &count);

    printf("Return value: %d\n", result);

    if (result == 1) {
        printf("Selected sensors: ");
        for (int i = 0; i < count; i++)
            printf("%d ", sensor[i]);
        printf("\nCount: %d\n", count);
    } else {
        printf("No complete coverage found.\n");
    }

    free(sensor);
    free(grid);

    return 0;
}
