#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void merge_sort(char *arr,char *arr2,int middle,int left,int right) {

    int i= left,j=middle+1,k=left;

    while (i<=middle && j<=right) {

        if (arr[i]<=arr[j])
            arr2[k++]=arr[i++];

        else
            arr2[k++]=arr[j++];
    }

    while (i<=middle)
        arr2[k++]=arr[i++];

    while (j<=right)
        arr2[k++]=arr[j++];

    for (k=left; k<=right; k++)
        arr[k]=arr2[k];
}

void merge(char *arr,char *arr2,int left,int right) {

    if (left>=right)
        return;

    int middle = left + (right-left)/2;

    merge(arr,arr2,left,middle);
    merge(arr,arr2,middle+1,right);

    merge_sort(arr,arr2,middle,left,right);
}

char *merge_string(char *s1,char *s2) {

    if (!s1 || !s2)
        return NULL;

    for (int i=0;s1[i];i++) {

        if (!isalpha(s1[i]))
            return NULL;

        if (!islower(s1[i]))
            return NULL;
    }

    for (int i=0;s2[i];i++) {

        if (!isalpha(s2[i]))
            return NULL;

        if (!islower(s2[i]))
            return NULL;
    }

    int n = strlen(s1)+ strlen(s2)+1;

    char *merge_string = malloc(n);

    if (!merge_string)
        return NULL;

    strcpy(merge_string,s1);
    strcat(merge_string,s2);

    char *copy = malloc(n);

    if (!copy) {
        free(merge_string);
        return NULL;
    }

    merge(merge_string,copy,0,n-2);

    free(copy);

    return merge_string;
}

int main() {

    char s1[30] = "abcwendwrdxyz";
    char s2[30] = "defpwoaaaekwdawgh";

    char *string = merge_string(s1,s2);

    if (string) {
        printf("%s\n", string);
        free(string);
    }

    return 0;
}
