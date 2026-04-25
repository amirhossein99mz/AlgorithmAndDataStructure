#include <stdio.h>
#include <stdlib.h>

void invert_string(char *s1,char **s2);

int main() {
    char *s1 = "ABCDDDDZYXWEFG";
    char *s2;

    invert_string(s1, &s2);
    free(s2);

    return 0;
}
