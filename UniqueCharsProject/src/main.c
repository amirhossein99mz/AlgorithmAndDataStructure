#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void erase_duplicate(char *str);

int main() {
    char *str = strdup("aa;;;bbbab");
    erase_duplicate(str);
    printf("%s", str);
    free(str);
    return 1;
}
