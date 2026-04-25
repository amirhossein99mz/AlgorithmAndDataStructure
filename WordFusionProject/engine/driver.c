#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listB {
    char *string;
    struct listB *next;
} listB_t;

typedef struct listA {
    listB_t *strings;
    struct listA *next;
} listA_t;

listB_t *createListB(char *st);
listA_t *createListA(listB_t *list);
listB_t *merge(listA_t *head);

int main() {
    listB_t *b1 = createListB("apple");
    b1->next = createListB("banana");

    listB_t *b2 = createListB("banana");
    b2->next = createListB("mango");

    listA_t *a1 = createListA(b1);
    listA_t *a2 = createListA(b2);
    a1->next = a2;

    listB_t *result = merge(a1);

    for (listB_t *t = result; t; t = t->next) {
        printf("%s -> ", t->string);
    }
    printf("NULL\n");

    return 0;
}
