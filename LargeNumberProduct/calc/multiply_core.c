#include <stdio.h>
#include <stdlib.h>

void mul(int *v1,int *v2,int n,int **pv) {

    int *temp = realloc(*pv, 2*n*sizeof(int));
    if (!temp)return;
    *pv = temp;
    for (int i=0;i<n*2;i++) (*pv)[i]=0;

    for (int i=n-1;i>=0;i--) {
        for (int j=n-1;j>=0;j--) {

            int pos = i+j+1;

            (*pv)[pos]+= (v1[i]*v2[i]);

            (*pv)[pos-1] = (*pv)[pos]/10;

            (*pv)[pos]%=10;
        }
    }
}
