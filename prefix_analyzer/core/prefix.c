#include <stdio.h>

void find_prefix(char **arr, int size) {
    int pos = 0;
    char output[21];

    while (1) {
        char c = arr[0][pos];
        if (c == '\0') break;

        int ok = 1;
        for (int i = 1; i < size; i++) {
            if (arr[i][pos] != c) {
                ok = 0;
                break;
            }
        }

        if (!ok) break;

        output[pos++] = c;
    }

    output[pos] = '\0';
    printf("%s\n", output);
}
