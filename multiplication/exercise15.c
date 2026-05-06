#include <stdio.h>
#include <stdlib.h>

void mul(int *v1,int *v2,int n,int **pv) {

    *pv=(int*)calloc(2*n,sizeof(int));

    for (int i=n-1;i>=0;i--) {

        for (int j=n-1;j>=0;j--) {

            int pos=i+j+1;

            int product=v1[i]*v2[j]+(*pv)[pos];

            (*pv)[pos]=product%10;
            (*pv)[pos-1]+=product/10;
        }
    }

    for (int i=2*n-1;i>0;i--) {

        if ((*pv)[i]>=10) {
            (*pv)[i-1]+=(*pv)[i]/10;
            (*pv)[i]%=10;
        }
    }
}

int main() {

    int v1[]={0,3,2};
    int v2[]={2,4,3};

    int n=3;

    int *pv=NULL;

    mul(v1,v2,n,&pv);

    printf("Result: ");

    for (int i=0;i<2*n;i++)
        printf("%d",pv[i]);

    printf("\n");

    free(pv);

    return 0;
}
