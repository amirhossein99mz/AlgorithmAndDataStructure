#include <stdio.h>
#include <stdlib.h>

typedef struct tree_t {
    int data;
    struct tree_t *left;
    struct tree_t *right;
} tree_t;

tree_t *create_node(int data) {
    tree_t *node = malloc(sizeof(tree_t));
    if (!node) return NULL;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int count(tree_t *node) {
    if (!node) return 0;
    return 1 + count(node->left) + count(node->right);
}

void storeInorder(tree_t *node, int *arr, int *i) {
    if (!node) return;
    storeInorder(node->left, arr, i);
    arr[(*i)++] = node->data;
    storeInorder(node->right, arr, i);
}

void fillLevelOrder(tree_t *root, int *arr, int n) {
    tree_t **queue = malloc(n * sizeof(tree_t *));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 0;

    while (front < rear) {
        tree_t *curr = queue[front++];
        curr->data = arr[i++];

        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }

    free(queue);
}

tree_t *convert_bst_to_min_heap(tree_t *root) {
    if (!root) return NULL;

    int n = count(root);
    int *arr = malloc(n * sizeof(int));

    int i = 0;
    storeInorder(root, arr, &i);

    fillLevelOrder(root, arr, n);

    free(arr);
    return root;
}

/* Simple test */
void printLevelOrder(tree_t *root) {
    if (!root) return;

    tree_t *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        tree_t *curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    tree_t *root = create_node(4);
    root->left = create_node(2);
    root->right = create_node(6);
    root->left->left = create_node(1);
    root->left->right = create_node(3);
    root->right->left = create_node(5);
    root->right->right = create_node(7);

    root = convert_bst_to_min_heap(root);

    printLevelOrder(root);
    printf("\n");

    return 0;
}
