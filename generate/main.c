
#include <stdio.h>
#include <stdlib.h>

void rec(FILE *fp, int n, int pos, int arr[], int evenSum, int oddSum) {

    if (pos == n) {
        if (evenSum == oddSum) {
            for (int i = 0; i < n; i++)
                fprintf(fp, "%d", arr[i]);
            fprintf(fp, "\n");
        }
        return;
    }

    for (int d = 0; d < 10; d++) {

        // even positions -> even digits
        if (pos % 2 == 0 && d % 2 != 0) continue;

        // odd positions -> odd digits
        if (pos % 2 == 1 && d % 2 == 0) continue;

        arr[pos] = d;

        if (d % 2 == 0)
            rec(fp, n, pos + 1, arr, evenSum + d, oddSum);
        else
            rec(fp, n, pos + 1, arr, evenSum, oddSum + d);
    }
}

void generate(char *name, int n) {
    FILE *fp = fopen(name, "w");
    if (!fp) return;

    int *arr = malloc(n * sizeof(int));

    rec(fp, n, 0, arr, 0, 0);

    free(arr);
    fclose(fp);
}

int main() {
    generate("output.txt", 4);
    return 0;
}
