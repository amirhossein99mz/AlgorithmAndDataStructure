#include <stdio.h>
#include <stdlib.h>

// Global best-solution trackers (updated whenever a better combination is found)
int max_euro   = 0;
int *best_euro;
int *best_weight;

/* ──────────────────────────────────────────────
 * print: displays each selected parcel's value
 * and weight, then the total maximum value.
 * ────────────────────────────────────────────── */
void print(int max_euro, int *best_euro, int *best_weight, int pos) {
    for (int i = 0; i < pos; i++) {
        printf("cost:%d, weight:%d\n", best_euro[i], best_weight[i]);
    }
    printf("Total value: %d\n", max_euro);
}

/* ──────────────────────────────────────────────
 * simple_combination: recursive combination
 * generator. Tries every subset of parcels.
 * When all positions are filled (pos >= n),
 * checks if total weight fits the truck and if
 * total value beats the current best.
 *
 * Parameters:
 *   weight, value - input arrays
 *   n             - total number of parcels
 *   load          - truck weight capacity
 *   cw            - current total weight of selected parcels
 *   cv            - current total value of selected parcels
 *   sol           - indices of currently selected parcels
 *   start         - next candidate index to consider
 *   pos           - number of parcels selected so far
 * ────────────────────────────────────────────── */
void simple_combination(float *weight, float *value, int n, float load,
                        int cw, int cv, int *sol, int start, int pos) {

    if (pos >= n) {
        if (cw <= load && cv > max_euro) {
            max_euro = cv;
            for (int i = 0; i < pos; i++) best_euro[i]   = (int)value[sol[i]];
            for (int i = 0; i < pos; i++) best_weight[i] = (int)weight[sol[i]];
        }
        return;
    }

    for (int i = start; i < n; i++) {
        sol[pos] = i;
        simple_combination(weight, value, n, load,
                           cw + (int)weight[i], cv + (int)value[i],
                           sol, i + 1, pos + 1);  // start=i+1 avoids re-picking; pos+1 advances slot
    }
}

/* ──────────────────────────────────────────────
 * load_truck: entry point.
 *   Allocates workspace and launches the search.
 * ────────────────────────────────────────────── */
void load_truck(float *weight, float *value, int n, float load) {
    best_euro   = malloc(n * sizeof(int));
    best_weight = malloc(n * sizeof(int));
    int sol[n];
    simple_combination(weight, value, n, load, 0, 0, sol, 0, 0);
}

int main() {
    float weight[] = {10.0f, 15.0f, 25.5f, 39.5f, 17.0f};
    float value[]  = {19.99f, 9.50f, 15.00f, 27.50f, 11.40f};
    int   n        = 5;
    float load     = 50.0f;

    load_truck(weight, value, n, load);

    printf("Best combination:\n");
    print(max_euro, best_euro, best_weight, n);

    free(best_euro);
    free(best_weight);
    return 0;
}
