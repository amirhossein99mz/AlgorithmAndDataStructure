
#include <stdio.h>
#include <string.h>

// returns length and prints substring
int common_substring(char *str1, char *str2) {

    int max = 0;
    int end_index = 0; // end position in str1

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){

            int k = 0;

            while(i+k<n1 && j+k<n2 && str1[i+k] == str2[j+k]){
                k++;
            }

            if(k > max){
                max = k;
                end_index = i + k - 1;
            }
        }
    }

    // print substring
    if(max > 0){
        for(int i=end_index - max + 1; i<=end_index; i++){
            printf("%c", str1[i]);
        }
        printf("\n");
    }

    return max;
}

int main() {

    char str1[] = "123ABCD34EFG";
    char str2[] = "XXXABCE124YABCD";

    int len = common_substring(str1, str2);
    printf("Length = %d\n", len);

    return 0;
}
