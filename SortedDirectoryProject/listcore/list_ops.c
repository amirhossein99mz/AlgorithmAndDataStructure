#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t {
    char *name;
    char *surname;
    struct list_t *next;
    struct list_t *prev;
}list_t;

list_t *createList(char *name, char *surname) {
    list_t *list = malloc(sizeof(list_t));
    if (!list)return NULL;
    list->name = strdup(name);
    list->surname = strdup(surname);
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void freeList(list_t *head) {
    list_t *temp = head;
    while (temp) {
        list_t *next = temp->next;
        free(temp->surname);
        free(temp->name);
        free(temp);
        temp = next;
    }
}

int order_insert(list_t *list,char *surname,char *name) {

    list_t *newNode = createList(name, surname);
    if (!newNode)return 0;

    if (!list){list = newNode; return 1;}

    list_t *cur = list;
    list_t *prev = NULL;

    while (cur) {

        int cmp1 = strcmp(surname,cur->surname);
        int cmp2 = strcmp(name,cur->name);

        if (cmp1==cmp2 && cmp1==0) {
            free(cur->name);
            free(cur->surname);
            free(cur);
            return 0;
        }

        if (cmp1>0 || (cmp1==0 && cmp2>0)) {
            newNode->next = cur;
            newNode->prev = prev;

            if (prev)prev->next = newNode;
            if (cur)cur->prev = newNode;
        }

        if (cmp1<0 || (cmp1==0 && cmp2<0)) {
            newNode->next = prev;

            if (prev)prev->prev = newNode;
        }

        prev = cur;
        cur = cur->next;
    }

    newNode->prev = prev;
    if (prev)prev->next = newNode;

    return 1;
}
