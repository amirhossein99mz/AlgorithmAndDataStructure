
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct node_t {
    char *str;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *create_node(const char *str) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (!node) return NULL;
    node->str = strdup(str);
    node->left = node->right = NULL;
    return node;
}

void free_node(node_t *node) {
    if (!node) return;
    free_node(node->left);
    free_node(node->right);
    free(node->str);
    free(node);
}

// check if string exists in BST
int is_check(node_t *node, node_t *root) {
    if (!root) return 0;
    int cmp = strcmp(node->str, root->str);
    if (cmp == 0) return 1;
    if (cmp < 0) return is_check(node, root->left);
    return is_check(node, root->right);
}

// check if string exists in ALL BSTs
int if_all_in(node_t *node, node_t *root[N]) {
    for (int i = 1; i < N && root[i]; i++) {
        if (!is_check(node, root[i])) return 0;
    }
    return 1;
}

// inorder traversal of first tree
void inorder(node_t *node, node_t *root[N]) {
    if (!node) return;
    inorder(node->left, root);
    if (if_all_in(node, root)) {
        printf("%s\n", node->str);
    }
    inorder(node->right, root);
}

// main required function
void display_common(node_t *root[N]) {
    if (!root || !root[0]) return;
    inorder(root[0], root);
}
