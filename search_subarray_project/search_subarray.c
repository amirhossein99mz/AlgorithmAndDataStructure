#include <stdio.h>

void searchSubArray(float *v,int n ,int k) {

    float max_sum = -1;
    float max_diff = -1;

    float array_max_sum[k];
    float array_max_diff[k];

    for (int i=0;i<=n-k;i++) {

        int nn = i+k;

        float sum = 0;
        float max_num = -1;
        float min_num = 1000;

        for (int j=i;j<nn;j++) {

            sum += v[j];

            if (v[j]>max_num)
                max_num = v[j];

            if (v[j]<min_num)
                min_num = v[j];
        }

        float diff = max_num - min_num;

        if (diff > max_diff) {

            max_diff = diff;

            int index = 0;

            for (int j=i;j<nn && index<k;j++,index++) {
                array_max_diff[index] = v[j];
            }
        }

        if (sum > max_sum) {

            max_sum = sum;

            int index = 0;

            for (int j=i;j<nn && index<k;j++,index++) {
                array_max_sum[index] = v[j];
            }
        }
    }

    printf("Max sum is %f\n",max_sum);

    for (int i=0;i<k;i++) {
        printf("%.2f ",array_max_sum[i]);
    }

    printf("\n");

    printf("Max diff is %.2f\n",max_diff);

    for (int i=0;i<k;i++) {
        printf("%.2f ",array_max_diff[i]);
    }
}

int main() {

    float v[10] = {12.5,2.1,3.3,4.1,5.4,6.2,7.9,8.3,-9.9,5.1};

    searchSubArray(v,10,3);

    return 0;
}
