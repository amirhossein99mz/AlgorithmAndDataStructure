
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t {
    char *str;
    struct list_t *next;
} list_t;

list_t *createList(char *string) {
    if (!string) return NULL;

    list_t *list = malloc(sizeof(list_t));
    if (!list) return NULL;

    list->str = strdup(string);
    if (!list->str) {
        free(list);
        return NULL;
    }

    list->next = NULL;
    return list;
}

void freeList(list_t *list) {
    while (list) {
        list_t *next = list->next;
        free(list->str);
        free(list);
        list = next;
    }
}

typedef struct bst_t {
    int data;
    struct bst_t *left;
    struct bst_t *right;
    list_t *strings;
} bst_t;

bst_t *createBST(int data, list_t *list) {
    if (!list) return NULL;

    bst_t *bst = malloc(sizeof(bst_t));
    if (!bst) return NULL;

    bst->data = data;
    bst->left = NULL;
    bst->right = NULL;
    bst->strings = list;

    return bst;
}

void freeBST(bst_t *bst) {
    if (!bst) return;

    freeBST(bst->left);
    freeBST(bst->right);
    freeList(bst->strings);
    free(bst);
}

bst_t *insert_node(bst_t *root, bst_t *bst) {
    if (!root) return bst;

    if (bst->data < root->data) {
        root->left = insert_node(root->left, bst);
    }
    else if (bst->data > root->data) {
        root->right = insert_node(root->right, bst);
    }
    else {
        list_t *temp = root->strings;
        while (temp->next) temp = temp->next;
        temp->next = bst->strings;
        free(bst);
    }

    return root;
}

bst_t *insert(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return NULL;

    int key;
    char line[100];
    bst_t *head = NULL;

    while (fscanf(fp, "%d %99s", &key, line) == 2) {
        list_t *list = createList(line);
        if (!list) {
            fclose(fp);
            return NULL;
        }

        bst_t *bst = createBST(key, list);
        if (!bst) {
            fclose(fp);
            return NULL;
        }

        head = insert_node(head, bst);
    }

    fclose(fp);
    return head;
}

void printBST(bst_t *root) {
    if (!root) return;

    printBST(root->left);

    printf("%d: ", root->data);
    list_t *temp = root->strings;
    while (temp) {
        printf("%s ", temp->str);
        temp = temp->next;
    }
    printf("\n");

    printBST(root->right);
}

int main() {
    bst_t *root = insert("input.txt");
    printBST(root);
    freeBST(root);
    return 0;
}
