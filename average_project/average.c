#include <stdio.h>

#define R 3
#define C 5

void avg(int matI[R][C], float matO[R][C]) {

    for (int i = 0; i < R; i++) {

        for (int j = 0; j < C; j++) {

            int sum = matI[i][j];
            int count = 1;

            // right top
            int row = i, col = j;

            while (--row >= 0 && ++col < C) {
                sum += matI[row][col];
                count++;
            }

            // right bottom
            row = i;
            col = j;

            while (++row < R && ++col < C) {
                sum += matI[row][col];
                count++;
            }

            // left top
            row = i;
            col = j;

            while (--row >= 0 && --col >= 0) {
                sum += matI[row][col];
                count++;
            }

            // left bottom
            row = i;
            col = j;

            while (++row < R && --col >= 0) {
                sum += matI[row][col];
                count++;
            }

            matO[i][j] = (float)sum / count;
        }
    }
}

int main() {

    int matI[R][C] = {
        {20, 33, 41, 51, 10},
        {42, 11, 17, 23, 45},
        {21, 19, 82, 10, 30}
    };

    float matO[R][C];

    avg(matI, matO);

    printf("Output matrix:\\n\\n");

    for (int i = 0; i < R; i++) {

        for (int j = 0; j < C; j++) {
            printf("%.2f ", matO[i][j]);
        }

        printf("\\n");
    }

    return 0;
}
