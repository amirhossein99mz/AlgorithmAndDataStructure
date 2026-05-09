#include <stdio.h>

int isValid(int *sol,int n) {

    int sum_even=0;
    int sum_odd=0;

    for (int i=0;i<n;i++) {

        if (!(i%2)) {
            if (sol[i]%2) return 0;
            sum_even += sol[i];
        }

        else {
            if (!(sol[i]%2)) return 0;
            sum_odd += sol[i];
        }
    }

    return sum_even==sum_odd;
}

void write_to_file(int *sol,int n,FILE *file) {

    if (!sol) return;

    for (int i=0;i<n;i++) {
        fprintf(file,"%d",sol[i]);
    }

    fprintf(file,"\n");
}

void arrangement(int n,int k,int pos,int *sol,int *val,FILE *file) {

    if (pos>=k) {

        if (isValid(sol,pos)) {
            write_to_file(sol,n,file);
        }

        return;
    }

    for (int i=0;i<n;i++) {

        // these 2 lines avoid generating wrong numbers
        if (!(pos%2) && val[i]%2) continue;
        if (pos%2 && !(val[i]%2)) continue;

        sol[pos] = val[i];

        arrangement(n,k,pos+1,sol,val,file);
    }
}

void generate(char *name,int n) {

    int arr[10];

    for (int i=0;i<10;i++) {
        arr[i]=i;
    }

    int sol[n];

    FILE *file = fopen(name,"w");

    if (!file) return;

    arrangement(10,n,0,sol,arr,file);

    fclose(file);
}

int main() {

    generate("output.txt",4);

    return 0;
}
