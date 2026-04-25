#include <stdio.h>
#include <stdlib.h>

typedef struct list_t {
    char *name;
    char *surname;
    struct list_t *next;
    struct list_t *prev;
}list_t;

int order_insert(list_t *list,char *surname,char *name);
list_t *createList(char *name, char *surname);

int main() {

    list_t *head = createList("John","Smith");

    order_insert(head,"Brown","Alice");
    order_insert(head,"Smith","Adam");

    for(list_t *t=head; t; t=t->next) {
        printf("%s %s -> ", t->surname, t->name);
    }
    printf("NULL
");

    return 0;
}
