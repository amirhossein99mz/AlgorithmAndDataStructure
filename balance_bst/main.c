#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *create_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    if (!node) return NULL;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

node_t *insert(node_t *root, int data) {
    if (!root) return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int count(node_t *root) {
    if (!root) return 0;
    return 1 + count(root->left) + count(root->right);
}

void store_inorder(node_t *root, int *v, int *i) {
    if (!root) return;

    store_inorder(root->left, v, i);
    v[(*i)++] = root->data;
    store_inorder(root->right, v, i);
}

node_t *build_balanced(int *v, int left, int right) {
    if (left > right) return NULL;

    int mid = left + (right - left) / 2;
    node_t *root = create_node(v[mid]);

    root->left = build_balanced(v, left, mid - 1);
    root->right = build_balanced(v, mid + 1, right);

    return root;
}

node_t *balance(node_t *root, int *v, int n) {
    n = count(root);

    v = malloc(n * sizeof(int));
    int i = 0;

    store_inorder(root, v, &i);

    return build_balanced(v, 0, n - 1);
}

// simple test
void print_inorder(node_t *root) {
    if (!root) return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

int main() {
    node_t *root = NULL;

    // skewed BST
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    int *v = NULL;

    root = balance(root, v, 0);

    print_inorder(root);
    printf("\n");

    return 0;
}
