#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erase_duplicate(char *str) {

    char *copy = malloc(strlen(str) +1);
    int index=0;

    for (int i=0;str[i];i++) {
        int equal =0;
        for (int j=i+1;str[j]; j++) {
            if (str[j] == str[i]) {
                equal = 1;
                break;
            }
        }
        if (equal) {
            int found =0;
            for (int k=0;copy[k];k++) {
                if (copy[k] == str[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) copy[index++] = str[i];
        }
        copy[index] = '\0';
    }

    str =strdup(copy);
    printf("%s\n",str);
}

int main(int argc,char **argv) {

    char st[100]= "787878999999000089897";
    erase_duplicate(st);
}
