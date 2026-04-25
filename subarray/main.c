
#include <stdio.h>
#include <float.h>

void printArray(double *a, int k) {
    for (int i = 0; i < k; i++) printf("%.1f ", a[i]);
    printf("\n");
}

void searchSubArray(double *v, int n, int k) {

    double max_sum = -DBL_MAX;
    double max_diff = -DBL_MAX;

    double best_sum[k];
    double best_diff[k];

    for (int i = 0; i <= n - k; i++) {

        double sum = 0;
        double local[k];

        double mx = v[i];
        double mn = v[i];

        for (int j = 0; j < k; j++) {
            local[j] = v[i + j];
            sum += v[i + j];

            if (v[i + j] > mx) mx = v[i + j];
            if (v[i + j] < mn) mn = v[i + j];
        }

        if (sum > max_sum) {
            max_sum = sum;
            for (int t = 0; t < k; t++) best_sum[t] = local[t];
        }

        if ((mx - mn) > max_diff) {
            max_diff = mx - mn;
            for (int t = 0; t < k; t++) best_diff[t] = local[t];
        }
    }

    printf("Max sum subarray:\n");
    printArray(best_sum, k);

    printf("Max difference subarray:\n");
    printArray(best_diff, k);
}

int main() {
    double v[] = {12.5,2.1,3.3,4.1,5.4,6.2,7.9,8.3,-9.9,5.1};
    int n = 10, k = 3;

    searchSubArray(v, n, k);

    return 0;
}
