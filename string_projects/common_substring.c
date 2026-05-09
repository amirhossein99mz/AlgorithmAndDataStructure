#include <stdio.h>
#include <string.h>

int common_substring(char *str1,char *str2) {

    int max_count = -1;

    for (int i=0;i<strlen(str1);i++) {

        for (int j=0;j<strlen(str2);j++) {

            int count = 0,k = 0;

            while (str1[i+k] && str2[j+k] &&
                   str1[i+k] == str2[j+k]) {

                k++;
                count++;
            }

            if (count > max_count)
                max_count = count;
        }
    }

    return max_count;
}

int main() {

    char str1[] = "123ABCD34EFG";
    char str2[] = "XXXABCE124YABCD";

    printf("%d\n",common_substring(str1,str2));

    return 0;
}
