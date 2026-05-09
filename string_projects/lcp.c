#include <stdio.h>

void lcp(char **string ,int n) {

    int max=0;

    char buffer[21];

    int index=0;

    for (int i=0; string[0][i]; i++) {

        int found = 1;

        for (int j=1; j<n; j++) {

            if (string[0][i] != string[j][i]) {

                found=0;
                break;
            }
        }

        if (!found) break;

        buffer[index++] = string[0][i];
    }

    buffer[index] = '\0';

    max = index;

    printf("%d %s",max,buffer);
}

int main() {

    char *arr[] = {"flower","flow","flight"};

    lcp(arr,3);

    return 0;
}
