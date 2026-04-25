#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) {
    struct node *new = malloc(sizeof(struct node));
    if (!new)return NULL;
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void freeNode(struct node *root) {
    if (!root)return;

    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

void double_tree(struct node *root,char flag) {
    if (!root)return;
    double_tree(root->left,flag);
    double_tree(root->right,flag);

    struct node *temp = newNode(root->data);

    if (flag=='L') {
        temp->left =root->left;
        root->left = temp;
    }
    else if (flag=='R') {
        temp->right = root->right;
        root->right = temp;
    }
    free(temp);
}
