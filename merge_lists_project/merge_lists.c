
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef  struct listB_t {
    char *str;
    struct listB_t *next;
}listB_t;

listB_t *createListB(char *string) {
    listB_t *head = malloc(sizeof(listB_t));
    if (!head)return NULL;

    head->str = strdup(string);

    if (!head->str) {
        free(head);
        return NULL;
    }

    head->next = NULL;
    return head;
}

listB_t *addNode(listB_t *head,listB_t *node) {

    if (!head || strcmp(node->str,head->str)<0) {
        node->next = head;
        head = node;
        return head;
    }

    if (!strcmp(node->str,head->str))
        return head;

    if (head->next &&
        strcmp(node->str,head->next->str)>0) {

        head->next = addNode(head->next,node);
        return head;
    }

    node->next = head->next;
    head->next = node;

    return head;
}

void freeListB(listB_t *list) {

    if (!list)return;

    listB_t *temp = list;

    while (temp) {
        listB_t *next = temp->next;
        free(temp->str);
        free(temp);
        temp = next;
    }
}

typedef struct listA_t {
    listB_t *listB;
    struct listA_t *next;
}listA_t;

listA_t *createListA() {

    listA_t *head = malloc(sizeof(listA_t));

    if (!head)return NULL;

    head->listB = NULL;
    head->next = NULL;

    return head;
}

void freeListA(listA_t *listA) {

    listA_t *temp = listA;

    while (temp) {
        listA_t *next = temp->next;
        freeListB(temp->listB);
        free(temp);
        temp = next;
    }
}

listB_t *merge(listA_t *head) {

    if (!head)return NULL;

    listB_t *headB = NULL;

    for (listA_t *tempA = head;
         tempA;
         tempA = tempA->next) {

        for (listB_t *tempB = tempA->listB;
             tempB;
             tempB = tempB->next) {

            listB_t *newB =
                createListB(tempB->str);

            if (!newB) return NULL;

            headB = addNode(headB,newB);
        }
    }

    return headB;
}
