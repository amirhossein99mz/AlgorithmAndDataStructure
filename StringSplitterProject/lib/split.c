#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    char *string;
    struct node_t *next;
    struct node_t* prev;
}node_t;

node_t *create_node(char *string) {

    node_t *node = malloc(sizeof(node_t));
    if (!node)return NULL;

    node->string = (char*)malloc(strlen(string) + 1);
    if (!node->string)return NULL;

    strcpy(node->string, string);

    node->next = NULL;
    node->prev = NULL;

    return node;
}

void freeNode(node_t *node) {

    if (!node)return;
    node_t *temp = node;

    while (temp) {
        node_t *next = temp->next;
        free(temp->string);
        free(temp);
        temp = next;}
}

node_t *split_str(char *str) {
    char buffer[strlen(str) + 1];
    node_t *head = NULL;
    node_t **ptr = &head;
    int index=0;

    for (int i=0;;i++) {
        if (str[i]=='.' || str[i]=='\0') {
            buffer[index]='\0';
            index=0;
            node_t *newNode = create_node(buffer);
            newNode->next = *ptr;
            if (*ptr)(*ptr)->prev = newNode;
            *ptr = newNode;
        }
        if (str[i]=='\0')break;
        buffer[index++]=str[i];
    }
    return head;
}
