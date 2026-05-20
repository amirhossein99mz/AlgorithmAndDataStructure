#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_sum(int *arr,int n) {
    int sum=0;
    for (int i=0;i<n;i++) sum+=arr[i];
    return sum;
}

double calculate_average(int *sums,int n) {
    int sum=calculate_sum(sums,n);
    return (double)sum/n;
}

double calculate_variance(int *sums,int n,double average) {
    double sum=0;
    for (int i=0;i<n;i++) {
        double diff = sums[i]-average;
        sum += diff*diff;
    }
    return sum/(n-1);
}

// Recursive helper to generate partitions with balanced block sizes
void partition_recursive(int *vet,int n,int k,int start,int **blocks,int *block_sizes,int block_idx,double *min_var,int **best_blocks) {
    if (block_idx == k-1) {
        // Last block takes remaining elements
        block_sizes[block_idx] = n-start;
        for (int i=0;i<block_sizes[block_idx];i++) blocks[block_idx][i]=vet[start+i];

        // Compute sum per block
        int sums[k];
        for (int b=0;b<k;b++) sums[b]=calculate_sum(blocks[b],block_sizes[b]);
        double avg = calculate_average(sums,k);
        double var = calculate_variance(sums,k,avg);

        if (var<*min_var) {
            *min_var=var;
            // save best partition
            for (int b=0;b<k;b++) {
                for (int i=0;i<block_sizes[b];i++) best_blocks[b][i]=blocks[b][i];
            }
        }
        return;
    }

    // Determine allowed block sizes (floor or ceil of n/k)
    int min_size = n/k;
    int max_size = (n+k-1)/k; // ceil(n/k)

    for (int size=min_size; size<=max_size; size++) {
        if (start+size > n) continue;
        block_sizes[block_idx]=size;
        for (int i=0;i<size;i++) blocks[block_idx][i]=vet[start+i];
        partition_recursive(vet,n,k,start+size,blocks,block_sizes,block_idx+1,min_var,best_blocks);
    }
}

void partition(int *vet,int n,int k) {
    if (!vet || n<=0 || k<=0) return;

    int **blocks = malloc(k*sizeof(int*));
    int **best_blocks = malloc(k*sizeof(int*));
    int block_sizes[k];
    for (int i=0;i<k;i++) {
        blocks[i] = malloc(n*sizeof(int));
        best_blocks[i] = malloc(n*sizeof(int));
    }

    double min_var = 1e9;
    partition_recursive(vet,n,k,0,blocks,block_sizes,0,&min_var,best_blocks);

    printf("Minimum variance partition:\n");
    for (int i=0;i<k;i++) {
        printf("Block %d: ",i+1);
        for (int j=0;j<block_sizes[i];j++) printf("%d ",best_blocks[i][j]);
        printf("\n");
    }

    // Free memory
    for (int i=0;i<k;i++) {
        free(blocks[i]);
        free(best_blocks[i]);
    }
    free(blocks);
    free(best_blocks);
}

int main() {
    int vet[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int k = 3;
    partition(vet,n,k);
    return 0;
}