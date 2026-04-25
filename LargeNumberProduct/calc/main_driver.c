#include <stdio.h>
#include <stdlib.h>

void mul(int *v1,int *v2,int n,int **pv);

int main() {

    int v1[] = {0,3,2};
    int v2[] = {2,4,3};
    int n = 3;

    int *res = NULL;

    mul(v1,v2,n,&res);

    printf("Result: ");
    for(int i=0;i<2*n;i++) printf("%d", res[i]);
    printf("\n");

    free(res);
    return 0;
}
