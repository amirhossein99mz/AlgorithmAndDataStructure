#include <stdio.h>

void erase_duplicate(char *str) {

    int index=0;

    for (int i=0; str[i]; i++) {
        int found =0;
        for (int j=0; j<index; j++) {
            if (str[i]==str[j]) {found=1;break;}
        }

        if (!found) str[index++]=str[i];
    }
    str[index]='\0';
}
