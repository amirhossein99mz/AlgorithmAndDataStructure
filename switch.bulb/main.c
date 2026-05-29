#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_len = 100000;

int isValid(char *sol, int bulb) {
    for (int i = 0; i < bulb; i++) {
        int cnt = 0;
        for (int j = 0; sol[j]; j++) {
            if ((sol[j] - '0') == i)
                cnt++;
        }
        if (cnt % 2 == 0)
            return 0;
    }
    return 1;
}

void simple_combination(char **values,char *sol,int switchh,int bulb,int pos,int start,int *indices,int *best_indices) {
    if (isValid(sol, bulb)) {
        if (pos < min_len) {
            min_len = pos;
            for (int i = 0; i < pos; i++)
                best_indices[i] = indices[i];
        }
        return;
    }

    for (int i = start; i < switchh; i++) {
        char temp[100];
        strcpy(temp, sol);

        if (pos == 0) strcpy(sol, values[i]);
        else strcat(sol, values[i]);

        indices[pos] = i;

        simple_combination(values, sol, switchh, bulb, pos + 1, i + 1, indices, best_indices);

        strcpy(sol, temp);
    }
}

void switches(int **mat, int switchh, int bulb) {
    char **values = malloc(sizeof(char *) * switchh);

    for (int i = 0; i < switchh; i++) {
        values[i] = malloc(bulb + 1);
        int index = 0;

        for (int j = 0; j < bulb; j++)
            if (mat[i][j])
                values[i][index++] = '0' + j;

        values[i][index] = '\\0';
    }

    char *sol = malloc(100);
    sol[0] = '\\0';

    int *indices = malloc(sizeof(int) * switchh);
    int *best_indices = malloc(sizeof(int) * switchh);

    simple_combination(values, sol, switchh, bulb, 0, 0, indices, best_indices);

    if (min_len < 100000) {
        printf("Solution: ");
        for (int i = 0; i < min_len; i++)
            printf("%d ", best_indices[i]);
        printf("\\n");
    }

    free(sol);
    free(indices);
    free(best_indices);

    for (int i = 0; i < switchh; i++)
        free(values[i]);
    free(values);
}

int main(void) {
    int mat[4][4] = {
        {1,0,1,0},
        {0,1,0,1},
        {1,1,0,0},
        {0,0,1,1}
    };

    int *matt[4];
    for (int i = 0; i < 4; i++)
        matt[i] = mat[i];

    switches(matt, 4, 4);
    return 0;
}
