#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_string(char *s1,char **s2) {

    *s2 = malloc(strlen(s1)+1);if (!*s2)return;

    int index =0;
    while (index < strlen(s1)) {
        int start = index;
        while (index+1<strlen(s1) && s1[index] < s1[index+1])index++;
        int end = index;

        for (int j=start;j<=end;j++)(*s2)[j]=s1[end-j+start];
        index++;
    }
    (*s2)[strlen(s1)]='\0';
    printf("%s\n",*s2);
}
