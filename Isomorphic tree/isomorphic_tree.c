#include <stdio.h>
#include <stdlib.h>

// Isomorphic binary trees

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} tree;

int isomorphic(tree *rootA, tree *rootB) {

    if (rootA == NULL && rootB == NULL) return 1;
    if (rootA == NULL || rootB == NULL) return 0;
    if (rootA->data != rootB->data)     return 0;

    int swap  = isomorphic(rootA->left,  rootB->left)
             && isomorphic(rootA->right, rootB->right);

    int swap2 = isomorphic(rootA->left,  rootB->right) &&
                isomorphic(rootA->right, rootB->left);

    return swap || swap2;
}

// Helper: create a new node
tree* newNode(int data) {
    tree* node = (tree*)malloc(sizeof(tree));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

int main() {
    /*
     * Tree A:        Tree B:
     *      1              1
     *     / \            / \
     *    2   3          3   2
     *   /                    \
     *  4                      4
     *
     * These two trees ARE isomorphic.
     */

    tree* rootA = newNode(1);
    rootA->left         = newNode(2);
    rootA->right        = newNode(3);
    rootA->left->left   = newNode(4);

    tree* rootB = newNode(1);
    rootB->left          = newNode(3);
    rootB->right         = newNode(2);
    rootB->right->right  = newNode(4);

    if (isomorphic(rootA, rootB))
        printf("The two trees ARE isomorphic.\n");
    else
        printf("The two trees are NOT isomorphic.\n");

    return 0;
}
