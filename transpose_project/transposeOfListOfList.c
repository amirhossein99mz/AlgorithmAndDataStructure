#include <stdio.h>
#include <stdlib.h>

typedef struct list_t2 {
    int column;
    struct list_t2 *next;
    int value;
} list_t2;

list_t2 *create_list2(int data) {
    list_t2 *node = malloc(sizeof(list_t2));
    if (!node) return NULL;

    node->value = data;
    node->column = 0;
    node->next = NULL;

    return node;
}

list_t2 *addNode_list2(list_t2 *node, list_t2 *head) {

    if (!head)
        return node;

    list_t2 *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = node;

    head->column++;

    return head;
}

void free_list2(list_t2 *node) {

    while (node) {
        list_t2 *next = node->next;
        free(node);
        node = next;
    }
}

typedef struct list_t1 {
    int row;
    struct list_t1 *next;
    list_t2 *list;
} list_t1;

list_t1 *create_list1(list_t2 *numbers) {

    if (!numbers)
        return NULL;

    list_t1 *node = malloc(sizeof(list_t1));

    if (!node)
        return NULL;

    node->list = numbers;
    node->row = 0;
    node->next = NULL;

    return node;
}

list_t1 *addNode_list1(list_t1 *node, list_t1 *head) {

    if (!head)
        return node;

    list_t1 *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = node;

    head->row++;

    return head;
}

void free_list1(list_t1 *node) {

    while (node) {
        list_t1 *next = node->next;
        free_list2(node->list);
        free(node);
        node = next;
    }
}

void transposee(int mat[][100], int n) {

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void transpose(list_t1 *head1, list_t1 **head2) {

    if (!head1 || !head2)
        return;

    int row = head1->row + 1;
    int col = head1->list->column + 1;

    int mat[100][100];

    int i = 0;

    for (list_t1 *tempA = head1; tempA; tempA = tempA->next) {

        int j = 0;

        for (list_t2 *tempB = tempA->list; tempB; tempB = tempB->next) {

            mat[i][j] = tempB->value;
            j++;
        }

        i++;
    }

    if (row == col)
        transposee(mat, row);

    *head2 = NULL;

    for (i = 0; i < col; i++) {

        list_t2 *rowHead = NULL;

        for (int j = 0; j < row; j++) {

            list_t2 *newNode = create_list2(mat[i][j]);
            rowHead = addNode_list2(newNode, rowHead);
        }

        list_t1 *newNode1 = create_list1(rowHead);

        *head2 = addNode_list1(newNode1, *head2);
    }
}
