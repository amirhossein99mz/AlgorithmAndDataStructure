#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The 4 supported operators
char ops[4] = {'+', '-', '*', '/'};

/*
 * operation: applies operator op to a and b, returns integer result.
 * Division by zero is skipped (returns 0).
 */
int operation(int a, int b, char op) {
    int result = 0;
    if (op == '+') result = a + b;
    if (op == '-') result = a - b;
    if (op == '*') result = a * b;
    if (op == '/' && b != 0) result = a / b;
    return result;
}

/*
 * evaluate: given one permutation of numbers (sol), tries all 4^(n-1)
 * operator combinations. Evaluates left-to-right (equal precedence).
 * Prints every expression whose value equals result.
 */
void evaluate(int *sol, int n, int result) {
    // Total operator combinations: 4^(n-1)
    int total_operands = 1;
    for (int i = 0; i < n - 1; i++) total_operands *= 4;

    // Iterate over every operator combination encoded as a base-4 number
    for (int mask = 0; mask < total_operands; mask++) {
        int temp = mask;
        char chosen[n - 1];
        for (int i = 0; i < n - 1; i++) {
            chosen[i] = ops[temp % 4];
            temp /= 4;
        }

        // Evaluate left-to-right
        int val = sol[0];
        for (int i = 0; i < n - 1; i++)
            val = operation(val, sol[i + 1], chosen[i]);

        // Print if it matches the target
        if (val == result) {
            printf("%d", sol[0]);
            for (int i = 0; i < n - 1; i++)
                printf(" %c %d", chosen[i], sol[i + 1]);
            printf(" = %d\n", result);
        }
    }
}

/*
 * simple_permutation: generates all permutations of val[] into sol[]
 * using backtracking. Calls evaluate() when a full permutation is ready.
 */
void simple_permutation(int n, int pos, int *val, int *sol,
                        int *mark, int result) {
    if (pos >= n) {
        evaluate(sol, n, result);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i]    = 1;
            sol[pos]   = val[i];
            simple_permutation(n, pos + 1, val, sol, mark, result);
            mark[i]    = 0;
        }
    }
}

/*
 * calculator: entry point. Allocates workspace and launches the search.
 */
void calculator(int *v, int n, int result) {
    int *sol  = malloc(n * sizeof(int));
    int *mark = calloc(n, sizeof(int));

    simple_permutation(n, 0, v, sol, mark, result);

    free(sol);
    free(mark);
}

int main() {
    int v[]  = {3, 2, 25, 5};
    int n    = 4;
    int target = 5;

    printf("Expressions using {3, 2, 25, 5} that equal %d:\n\n", target);
    calculator(v, n, target);
    return 0;
}
