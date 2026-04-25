#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    char *string;
    struct node_t *next;
    struct node_t* prev;
}node_t;

node_t *split_str(char *str);

int main() {
    char str[] = "a.bb.ccc.dddd";

    node_t *list = split_str(str);

    for (node_t *t = list; t; t = t->next) {
        printf("%s -> ", t->string);
    }
    printf("NULL\n");

    return 0;
}
