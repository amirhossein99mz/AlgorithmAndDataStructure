#include <stdio.h>
#include <stdlib.h>

int *balance(int *flow,int n);

int main() {

    int flow[] = {10,-5,7,-8};
    int n = 4;

    int *res = balance(flow,n);

    printf("Best order: ");
    for(int i=0;i<n;i++) printf("%d ", res[i]);
    printf("\n");

    free(res);
    return 0;
}
