#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ---------------- Sparse matrix list structures ---------------- */

typedef struct list2_t {
    int data;
    int column_index;
    struct list2_t *next;
} list2_t;

list2_t *createList2(int key) {
    list2_t *newNode = malloc(sizeof(list2_t));
    if (!newNode) return NULL;

    newNode->data = key;
    newNode->column_index = 0;
    newNode->next = NULL;

    return newNode;
}

list2_t *addList2(list2_t *root, list2_t *node) {
    if (!root) return node;
    if (!node) return root;

    list2_t *temp = root;
    while (temp->next) temp = temp->next;

    temp->next = node;
    node->column_index = temp->column_index + 1;

    return root;
}

void freeList2(list2_t *root) {
    if (!root) return;

    list2_t *temp = root;
    while (temp) {
        list2_t *next = temp->next;
        free(temp);
        temp = next;
    }
}

typedef struct list1_t {
    int row_index;
    list2_t *first;
    struct list1_t *next;
} list1_t;

list1_t *createList1(list2_t *list) {
    list1_t *newNode = malloc(sizeof(list1_t));
    if (!newNode) return NULL;

    newNode->row_index = 0;
    newNode->next = NULL;
    newNode->first = list;

    return newNode;
}

list1_t *addList1(list1_t *root, list1_t *node) {
    if (!root) return node;
    if (!node) return root;

    list1_t *temp = root;
    while (temp->next) temp = temp->next;

    temp->next = node;
    node->row_index = temp->row_index + 1;

    return root;
}

void freeList1(list1_t *root) {
    if (!root) return;

    list1_t *temp = root;
    while (temp) {
        list1_t *next = temp->next;
        freeList2(temp->first);
        free(temp);
        temp = next;
    }
}

void transposee(int **source, int **dest, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dest[j][i] = source[i][j];
        }
    }
}

void transpose(list1_t *head, list1_t **head2) {
    if (!head || !head2) return;

    int row_index = 0;
    int column_index = 0;

    list1_t *temp1 = head;
    while (temp1) {
        int count = 0;
        list2_t *temp2 = temp1->first;

        while (temp2) {
            count++;
            temp2 = temp2->next;
        }

        if (count > column_index)
            column_index = count;

        row_index++;
        temp1 = temp1->next;
    }

    int **source = malloc(sizeof(int *) * row_index);
    int **des = malloc(sizeof(int *) * column_index);
    if (!source || !des) return;

    for (int i = 0; i < row_index; i++) {
        source[i] = calloc(column_index, sizeof(int));
        if (!source[i]) return;
    }

    for (int i = 0; i < column_index; i++) {
        des[i] = calloc(row_index, sizeof(int));
        if (!des[i]) return;
    }

    int r = 0;
    for (list1_t *temp = head; temp; temp = temp->next) {
        int c = 0;
        for (list2_t *temp2 = temp->first; temp2; temp2 = temp2->next) {
            source[r][c++] = temp2->data;
        }
        r++;
    }

    transposee(source, des, row_index, column_index);

    *head2 = NULL;

    for (int i = 0; i < column_index; i++) {
        list2_t *head22 = NULL;

        for (int j = 0; j < row_index; j++) {
            list2_t *node = createList2(des[i][j]);
            if (!node) return;

            head22 = addList2(head22, node);
        }

        list1_t *node1 = createList1(head22);
        if (!node1) return;

        *head2 = addList1(*head2, node1);
    }

    for (int i = 0; i < row_index; i++) free(source[i]);
    for (int i = 0; i < column_index; i++) free(des[i]);
    free(source);
    free(des);
}

/* ---------------- String to FIFO lists ---------------- */

typedef struct node_t {
    char *string;
    struct node_t *next;
} node_t;

node_t *createNode(char *string) {
    node_t *newNode = malloc(sizeof(node_t));
    if (!newNode) return NULL;

    newNode->string = malloc(strlen(string) + 1);
    if (!newNode->string) {
        free(newNode);
        return NULL;
    }

    strcpy(newNode->string, string);
    newNode->next = NULL;

    return newNode;
}

node_t *addNode(node_t *head, node_t *node) {
    if (!head && !node) return NULL;
    if (!node) return head;
    if (!head) return node;

    node_t *temp = head;
    while (temp->next) temp = temp->next;

    temp->next = node;
    return head;
}

void freeNodeList(node_t *head) {
    while (head) {
        node_t *next = head->next;
        free(head->string);
        free(head);
        head = next;
    }
}

void string_to_fifo(char *s, node_t **letter, node_t **digit) {
    if (!s || !letter || !digit) return;

    char line[100];
    FILE *fpIn = fopen(s, "r");
    if (!fpIn) return;

    fgets(line, 100, fpIn);
    fclose(fpIn);

    char alpha[100];
    int index_alpha = 0;

    char num[100];
    int index_num = 0;

    *letter = NULL;
    *digit = NULL;

    for (int i = 0; line[i];) {
        if (isalpha((unsigned char)line[i])) {
            while (isalpha((unsigned char)line[i])) {
                alpha[index_alpha++] = line[i++];
            }

            alpha[index_alpha] = '\0';
            index_alpha = 0;

            node_t *newNode = createNode(alpha);
            *letter = addNode(*letter, newNode);
        }
        else if (isdigit((unsigned char)line[i])) {
            while (isdigit((unsigned char)line[i])) {
                num[index_num++] = line[i++];
            }

            num[index_num] = '\0';
            index_num = 0;

            node_t *newNode = createNode(num);
            *digit = addNode(*digit, newNode);
        }
        else {
            i++;
        }
    }
}

int main(void) {
    FILE *fp = fopen("input.txt", "w");
    if (!fp) return 1;
    fprintf(fp, "abc123def45ghi6");
    fclose(fp);

    node_t *letters = NULL;
    node_t *digits = NULL;

    string_to_fifo("input.txt", &letters, &digits);

    printf("Letters FIFO: ");
    for (node_t *p = letters; p; p = p->next)
        printf("%s ", p->string);
    printf("\n");

    printf("Digits FIFO: ");
    for (node_t *p = digits; p; p = p->next)
        printf("%s ", p->string);
    printf("\n");

    freeNodeList(letters);
    freeNodeList(digits);

    return 0;
}
