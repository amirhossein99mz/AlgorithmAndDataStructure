
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list1 {
    int data;
    struct list1 *next;
} list1;

list1 *create_list(int num) {
    list1 *node = malloc(sizeof(list1));
    node->data = num;
    node->next = NULL;
    return node;
}

typedef struct bst_t {
    char *str;
    list1 *numbers;
    struct bst_t *left, *right;
} bst_t;

bst_t *create_bst(char *s, list1 *nums) {
    bst_t *node = malloc(sizeof(bst_t));
    node->str = strdup(s);
    node->numbers = nums;
    node->left = node->right = NULL;
    return node;
}

int exists(list1 *head, int val) {
    while (head) {
        if (head->data == val) return 1;
        head = head->next;
    }
    return 0;
}

void merge_lists(list1 **dst, list1 *src) {
    while (src) {
        if (!exists(*dst, src->data)) {
            list1 *n = create_list(src->data);
            n->next = *dst;
            *dst = n;
        }
        src = src->next;
    }
}

bst_t *insert(bst_t *root, bst_t *node) {
    if (!root) return node;

    int cmp = strcmp(root->str, node->str);

    if (cmp == 0) {
        merge_lists(&root->numbers, node->numbers);
        return root;
    }
    if (cmp > 0) root->left = insert(root->left, node);
    else root->right = insert(root->right, node);

    return root;
}

bst_t *file_to_bst_of_lists(char *name) {
    FILE *fp = fopen(name, "r");
    if (!fp) return NULL;

    bst_t *root = NULL;
    char buffer[100];
    int count;

    while (fscanf(fp, "%s %d", buffer, &count) == 2) {
        list1 *head = NULL;

        for (int i = 0; i < count; i++) {
            int x;
            fscanf(fp, "%d", &x);
            list1 *n = create_list(x);
            n->next = head;
            head = n;
        }

        bst_t *node = create_bst(buffer, head);
        root = insert(root, node);
    }

    fclose(fp);
    return root;
}

int main() {
    bst_t *root = file_to_bst_of_lists("input.txt");
    if (root) printf("BST created\n");
    return 0;
}
