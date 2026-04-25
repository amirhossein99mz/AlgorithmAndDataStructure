#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data);
void double_tree(struct node *root,char flag);

int main() {

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    double_tree(root, 'L');

    printf("Done\n");

    return 0;
}
