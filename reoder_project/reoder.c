#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr,int *arr2,int left,int middle,int right) {

    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) {

        if (arr[i] <= arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    while (i <= middle)
        arr2[k++] = arr[i++];

    while (j <= right)
        arr2[k++] = arr[j++];

    for (k = left; k <= right; k++) {
        arr[k] = arr2[k];
    }
}

void merge(int *arr,int *arr2,int left,int right) {

    if (left >= right) return;

    int middle = left + (right - left) / 2;

    merge(arr,arr2,left,middle);
    merge(arr,arr2,middle + 1,right);

    mergeSort(arr,arr2,left,middle,right);
}

void cde(int **mat,int r,int c) {

    int n = r * c;

    int *mat1D = malloc(n * sizeof(int));
    if (!mat1D) return;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mat1D[i * c + j] = mat[i][j];
        }
    }

    int *temp = malloc(n * sizeof(int));
    if (!temp) {
        free(mat1D);
        return;
    }

    merge(mat1D,temp,0,n - 1);

    for (int i = 0; i < n;) {

        int count = 1;
        int k = 1;

        while (i + k < n && mat1D[i] == mat1D[i + k]) {
            count++;
            k++;
        }

        printf("%d[%d]", mat1D[i], count);

        if (i + k < n)
            printf(", ");

        i += k;
    }

    printf("\\n");

    free(mat1D);
    free(temp);
}

int main() {

    int mat[4][3] = {
        {11,12,31},
        {42,32,31},
        {31,15,61},
        {12,11,31}
    };

    int **matt = malloc(4 * sizeof(int *));
    if (!matt) return -1;

    for (int i = 0; i < 4; i++) {

        matt[i] = malloc(3 * sizeof(int));

        if (!matt[i]) return -1;

        for (int j = 0; j < 3; j++) {
            matt[i][j] = mat[i][j];
        }
    }

    cde(matt,4,3);

    for (int i = 0; i < 4; i++) {
        free(matt[i]);
    }

    free(matt);

    return 0;
}
