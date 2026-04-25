#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listB {
    char *string;
    struct listB *next;
}listB_t;

listB_t *createListB(char *st) {
    listB_t *list = malloc(sizeof(listB_t));
    if (!list)return NULL;
    list->string = strdup(st);
    list->next = NULL;
    return list;
}

void freeListB(listB_t *list) {
    listB_t *temp = list;
    while (temp) {
        listB_t *next = temp->next;
        free(temp->string);
        free(temp);
        temp = next;
    }
}

typedef struct listA {
    listB_t *strings;
    struct listA *next;
}listA_t;

listA_t *createListA(listB_t *list) {
    if (!list)return NULL;
    listA_t *listA = malloc(sizeof(listA_t));
    if (!listA)return NULL;
    listA->strings = list;
    listA->next = NULL;
    return listA;
}

void freeListA(listA_t *list) {

    listA_t *temp = list;

    while (temp) {
        listA_t *next = temp->next;
        freeListB(temp->strings);
        free(temp);
        temp = next;
    }
}

listB_t *merge(listA_t *head) {
    if (!head) return NULL;
    listB_t *result = NULL;

    for (listA_t *tempA = head; tempA; tempA = tempA->next) {
        for (listB_t *tempB = tempA->strings; tempB; tempB = tempB->next) {

            listB_t **p = &result;

            while (*p && strcmp((*p)->string, tempB->string) < 0)p = &(*p)->next;

            if (*p && strcmp((*p)->string, tempB->string) == 0)continue;

            listB_t *listtB = createListB(tempB->string);
            listtB->next = *p;
            *p = listtB;
        }
    }
    return result;
}
