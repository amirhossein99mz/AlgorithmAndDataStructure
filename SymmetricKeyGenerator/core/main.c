#include <stdio.h>

int palindrome(char *str,int index,int n);

int main() {
    char test[] = "aA1-1Aa";
    if (palindrome(test,0,7))
        printf("Valid\n");
    else
        printf("Invalid\n");
    return 0;
}
