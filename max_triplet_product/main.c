#include <stdio.h>
#include <limits.h>

// O(n) solution
int max_triplet_product(int a[], int n) {
    if (n < 3) return 0;

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        // update max values
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        } else if (a[i] > max3) {
            max3 = a[i];
        }

        // update min values
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if (a[i] < min2) {
            min2 = a[i];
        }
    }

    int prod1 = max1 * max2 * max3;
    int prod2 = max1 * min1 * min2;

    return (prod1 > prod2) ? prod1 : prod2;
}

int main() {
    int a[] = {-10, -3, 5, 6, -2};
    int n = sizeof(a) / sizeof(a[0]);

    int result = max_triplet_product(a, n);
    printf("Max triplet product: %d\n", result);

    return 0;
}
