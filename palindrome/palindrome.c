#include <stdio.h>
#include <ctype.h>

int palindrome(char *str, int n, int index,char *s) {

    if (n!=7)return 0;
    if (index > n/2)return  1;

    if (index==0 && !islower(str[index]))return 0;
    if (index==1 && !isupper(str[index]))return 0;
    if (index==2 && !isdigit(str[index]))return 0;
    if (index==3) {
        int found =0;
        for (int i=0;i<2;i++) {
            if (s[i]==str[3]) {
                found=1;
                break;
            }
        }
        if (!found) return 0;
    }

    return palindrome(str, index+1, index+2,s);
}

int main() {
    char s[2]= {'-','+'};
    printf("%d\n", palindrome("aA1+1Aa", 7, 0,s));
}
