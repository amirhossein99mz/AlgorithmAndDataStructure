
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correctness(int *v, int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] < 0 || v[i] >= n) return 0;
    }

    // check duplicates
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] == v[j]) return 0;
        }
    }

    return 1;
}

char *reorder_string(char *s1, int *v) {
    if (!s1 || !v) return NULL;

    int n = strlen(s1);

    if (!correctness(v, n)) {
        printf("Invalid index array\n");
        return NULL;
    }

    char *s2 = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        s2[v[i]] = s1[i];
    }

    s2[n] = '\0';
    return s2;
}

int main() {
    char s1[] = "abcdefgh";
    int v[] = {7,4,3,0,1,2,5,6};

    char *res = reorder_string(s1, v);

    if (res) {
        printf("%s\n", res);
        free(res);
    }

    return 0;
}
