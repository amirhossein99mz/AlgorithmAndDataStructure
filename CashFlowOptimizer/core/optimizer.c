#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_difference = 1000;

int find_difference(int *sol,int n) {

    int sum=0;
    int max=sum;
    int min=sum;

    for(int i=0;i<n;i++) {
        sum+=sol[i];
        if (sum>max)max= sum;
        if (sum<min)min= sum;
    }
    return max-min;
}

void simple_premutation(int *flow,int n,int pos,int *sol,int *mark,int *result) {

    if (pos>=n) {
        int difference = find_difference(sol,n);
        if (difference<min_difference) {
            min_difference = difference;
            for (int i=0;i<n;i++) result[i] = sol[i];
        }
        return;
    }

    for (int i=0;i<n;i++) {
        if (!mark[i]) {
            mark[i]=1;
            sol[pos] = flow[i];
            simple_premutation(flow,n,pos+1,sol,mark,result);
            mark[i] = 0;
        }
    }
}

int *balance(int *flow,int n) {

    int *result = (int *)malloc(n*sizeof(int));
    int *sol = (int*)malloc(n*sizeof(int));
    int *mark = (int*)calloc(n,sizeof(int));

    simple_premutation(flow,n,0,sol,mark,result);

    free(sol);
    free(mark);

    return result;
}
