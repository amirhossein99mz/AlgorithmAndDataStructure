#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef  struct list_t {
    char *str;
    struct list_t *next;
    struct list_t *prev;
}list_t;

list_t *createList(char *string) {
    list_t *newNode = malloc(sizeof(list_t));
    if (!newNode)return NULL;
    newNode->str = strdup(string);
    if (!newNode->str)return NULL;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void freeList(list_t *list) {
    list_t *temp = list;
    while (temp) {
        list_t *next = temp->next;
        free(temp->str);
        free(temp);
        temp = next;
    }
}

typedef  struct bst_t {
    int data;
    list_t *first_string;
    struct bst_t *left;
    struct bst_t *right;
}bst_t;

bst_t *createBST(int key,list_t *head) {
    if (!head)return NULL;
    bst_t *newNode = malloc(sizeof(bst_t));
    if (!newNode)return NULL;
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->first_string = head;
    return newNode;
}

void freeBst_t(bst_t *head) {
    if (!head)return;
    bst_t *temp = head;

    freeList(temp->left->first_string);
    free(temp->left);

    freeList(temp->right->first_string);
    free(temp->right);

    free(temp);
}


bst_t *insertt(bst_t *head,bst_t *node) {
    if (!head)return node;

    if (node->data < head->data) {
        head->left = insertt(head->left,node);
    }
    else if (node->data > head->data) {
        head->right = insertt(head->right,node);
    }

    else {

        list_t *new = node->first_string;
        list_t * curList = head->first_string;
        list_t *prevList = NULL;
        while (curList) {
            prevList = curList;
            curList = curList->next;
        }
        new->prev = prevList;
        new->next = curList;
        if (prevList)prevList->next = new;
        if (curList)curList->prev = new;
    }

    return head;
}



bst_t *insert(char *name) {

    bst_t *head = NULL;

    FILE *fp = fopen(name,"r");
    if (!fp)return NULL;

    char line[MAX];
    int data;

    while (fscanf(fp,"%d %s",&data,line)==2) {
        list_t * newNode = createList(line);
        if (!newNode) {
            fclose(fp);
            return NULL;
        }
        bst_t *BST = createBST(data,newNode);
        if (!BST) {
            fclose(fp);
            return NULL;
        }

        head = insertt(head,BST);
    }

    return head;
}