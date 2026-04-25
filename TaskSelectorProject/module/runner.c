#include <stdio.h>
#include <stdlib.h>

void opt_task (int n, int *time, int *priority, int th, int *best, int *l, int *max);

int main() {
    int n = 4;
    int time[] = {2, 3, 4, 5};
    int priority[] = {3, 4, 5, 8};
    int th = 7;

    int best[4] = {0};
    int l = 0;
    int max = 0;

    opt_task(n, time, priority, th, best, &l, &max);

    printf("Selected indices: ");
    for (int i = 0; i < l; i++) {
        printf("%d ", best[i]);
    }
    printf("\nCount: %d\nMax value: %d\n", l, max);

    return 0;
}
