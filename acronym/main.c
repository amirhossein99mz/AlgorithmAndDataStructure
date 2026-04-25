
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValid(char *str, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (isalpha(str[i]) && isalpha(str[i+1])) return 0;
        if (isdigit(str[i]) && isdigit(str[i+1])) return 0;
    }

    int lower = 0, upper = 0;
    for (int i = 0; i < n; i++) {
        if (islower(str[i])) lower = 1;
        if (isupper(str[i])) upper = 1;
    }

    if (lower && upper) return 0;
    return 1;
}

void gen(char **val, char *sol, int pos, int n, int *sizes, FILE *out) {
    if (pos == n) {
        sol[n] = '\0';
        if (isValid(sol, n)) {
            fprintf(out, "%s\n", sol);
        }
        return;
    }

    for (int i = 0; i < sizes[pos]; i++) {
        sol[pos] = val[pos][i];
        gen(val, sol, pos + 1, n, sizes, out);
    }
}

void acronym(char *nameI, char *nameO) {
    FILE *in = fopen(nameI, "r");
    if (!in) return;

    FILE *out = fopen(nameO, "w");
    if (!out) return;

    int n;
    fscanf(in, "%d", &n);

    char **val = malloc(n * sizeof(char*));
    char buffer[128];

    for (int i = 0; i < n; i++) {
        fscanf(in, "%s", buffer);
        val[i] = strdup(buffer);
    }

    int *sizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        sizes[i] = strlen(val[i]);

    char *sol = malloc(n + 1);

    gen(val, sol, 0, n, sizes, out);

    for (int i = 0; i < n; i++) free(val[i]);
    free(val);
    free(sizes);
    free(sol);

    fclose(in);
    fclose(out);
}

int main() {
    acronym("input.txt", "output.txt");
    return 0;
}
