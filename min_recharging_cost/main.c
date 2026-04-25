#include <stdio.h>
#include <limits.h>

/*
 Greedy approach:
 At each step, among all reachable stations (within range R),
 pick the one with minimum cost.
 If none reachable → return -1.
*/

int findMinRechargingCost(int M, int R, int n, int positions[], int costs[]) {
    int current = 0;
    int totalCost = 0;

    while (current + R < M) {
        int nextIndex = -1;
        int minCost = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (positions[i] > current && positions[i] <= current + R) {
                if (costs[i] < minCost) {
                    minCost = costs[i];
                    nextIndex = i;
                }
            }
        }

        if (nextIndex == -1) return -1;

        current = positions[nextIndex];
        totalCost += costs[nextIndex];
    }

    return totalCost;
}

// test
int main() {
    int M = 25;
    int R = 10;
    int positions[] = {5, 10, 15, 20};
    int costs[] = {5, 2, 4, 1};
    int n = 4;

    int result = findMinRechargingCost(M, R, n, positions, costs);

    if (result == -1)
        printf("Impossible to reach destination\n");
    else
        printf("Minimum cost: %d\n", result);

    return 0;
}
