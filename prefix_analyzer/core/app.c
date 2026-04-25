#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_prefix(char **arr, int size);

int main() {
    char data[3][20] = {"flower", "flow", "flight"};

    char **arr = malloc(3 * sizeof(char *));
    if (!arr) return 1;

    for (int i = 0; i < 3; i++) {
        arr[i] = strdup(data[i]);
    }

    find_prefix(arr, 3);

    for (int i = 0; i < 3; i++) free(arr[i]);
    free(arr);

    return 0;
}
