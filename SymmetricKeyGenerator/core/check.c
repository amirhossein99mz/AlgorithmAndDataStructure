#include <stdio.h>
#include <ctype.h>

int palindrome(char *str,int index,int n) {

    if (n!=7)return 0;
    if (str[index]!=str[n-index-1])return 0;
    if ((index==0 || index==n-1) && !islower(str[index]))return 0;
    if ((index==1 || index==n-2) && !isupper(str[index]))return 0;
    if ((index==2 || index==n-3) && !isdigit(str[index]))return 0;
    if (index==3 && (str[index]!='-' || str[index]!='+'))return 0;

    palindrome(str,index+1,n);

    return 1;
}
