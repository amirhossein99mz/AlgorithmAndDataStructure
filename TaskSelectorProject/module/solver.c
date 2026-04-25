#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValid(int *time,int n,int th,int *sol) {
    int sum=0;
    for (int i=0;i<n;i++)sum+=time[sol[i]];
    return sum<=th;
}

void simple_combination(int start,int pos,int n, int *time, int *priority, int th, int *best, int *l, int *max,int *sol) {

    if (pos>0) {
        if (isValid(time, pos, th, sol)) {
            int current_sum=0;
            for (int i=0;i<pos;i++)current_sum+=priority[sol[i]];
            if (current_sum>*max) {
                *max=current_sum;
                *l=pos;
                for (int i=0;i<n;i++)best[i]=sol[i];
            }
        }
    }

    for (int i=start;i<n;i++) {
        sol[pos] = i;
        simple_combination(i+1,pos+1,n, time, priority, th, best, l, max,sol);
    }
}

void opt_task (int n, int *time, int *priority, int th, int *best, int *l, int *max) {
    int sol[n];
    simple_combination(0, 0, n, time, priority, th, best, l, max, sol);
}
