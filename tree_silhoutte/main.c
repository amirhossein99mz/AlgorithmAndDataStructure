#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    int data;
    char *str;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *create_node(int data, const char *s) {
    node_t *node = malloc(sizeof(node_t));
    if (!node) return NULL;
    node->data = data;
    node->str = strdup(s);
    node->left = node->right = NULL;
    return node;
}

int isLeaf(node_t *node) {
    return node && !node->left && !node->right;
}

void printNode(node_t *node) {
    if (node) printf("%d %s, ", node->data, node->str);
}

void printLeft(node_t *root) {
    while (root) {
        if (!isLeaf(root)) printNode(root);
        if (root->left) root = root->left;
        else root = root->right;
    }
}

void printLeaves(node_t *root) {
    if (!root) return;
    if (isLeaf(root)) {
        printNode(root);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printRight(node_t *root) {
    node_t *stack[100];
    int top = 0;

    while (root) {
        if (!isLeaf(root)) stack[top++] = root;
        if (root->right) root = root->right;
        else root = root->left;
    }

    for (int i = top - 1; i >= 0; i--) {
        printNode(stack[i]);
    }
}

void silhouette(node_t **root) {
    if (!root || !*root) return;

    node_t *curr = *root;

    printNode(curr);
    printLeft(curr->left);
    printLeaves(curr->left);
    printLeaves(curr->right);
    printRight(curr->right);

    printf("\n");
}

// simple test
int main() {
    node_t *root = create_node(1, "A");
    root->left = create_node(2, "B");
    root->right = create_node(7, "G");

    root->left->left = create_node(3, "C");
    root->left->right = create_node(4, "D");
    root->left->right->right = create_node(5, "E");
    root->left->right->right->right = create_node(6, "F");

    root->right->left = create_node(8, "H");
    root->right->right = create_node(9, "I");

    silhouette(&root);

    return 0;
}
