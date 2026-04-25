#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 5

/*
 * avg: for each element [i][j] of matI, computes the average of all
 * elements on both diagonals passing through [i][j] (including itself),
 * and stores the result in matO[i][j].
 *
 * The four diagonal directions explored from each cell are:
 *   right-bottom (+row, +col)
 *   right-top    (-row, +col)
 *   left-top     (-row, -col)
 *   left-bottom  (+row, -col)
 */
void avg(int matI[R][C], float matO[R][C]) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            float average = (float)matI[i][j];
            int row, col;
            int count = 1;

            // going right bottom
            row = 1; col = 1;
            while (i+row >= 0 && i+row < R && j+col >= 0 && j+col < C) {
                count++;
                average += (float)matI[i+row][j+col];
                row++; col++;
            }

            // going right top
            row = -1; col = 1;
            while (i+row >= 0 && i+row < R && j+col >= 0 && j+col < C) {
                count++;
                average += (float)matI[i+row][j+col];
                row--; col++;
            }

            // going left top
            row = -1; col = -1;
            while (i+row >= 0 && i+row < R && j+col >= 0 && j+col < C) {
                count++;
                average += (float)matI[i+row][j+col];
                row--; col--;
            }

            // going left bottom
            row = 1; col = -1;
            while (i+row >= 0 && i+row < R && j+col >= 0 && j+col < C) {
                count++;
                average += (float)matI[i+row][j+col];
                row++; col--;
            }

            matO[i][j] = average / count;
        }
    }
}

int main() {
    int matI[R][C] = {
        {2, 3, 4, 5, 0},
        {4, 1, 7, 3, 3},
        {2, 9, 8, 1, 0}
    };

    float matO[R][C];
    avg(matI, matO);

    printf("Input matrix:\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) printf("%4d ", matI[i][j]);
        printf("\n");
    }

    printf("\nOutput matrix (diagonal averages):\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) printf("%6.2f ", matO[i][j]);
        printf("\n");
    }

    return 0;
}
