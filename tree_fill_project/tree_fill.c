#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_t {
    char *string;
    struct tree_t *left;
    struct tree_t *right;
} tree_t;

tree_t *createTree(char *string) {
    if (!string) return NULL;
    tree_t *node = malloc(sizeof(tree_t));
    if (!node) return NULL;

    node->string = strdup(string);
    if (!node->string) {
        free(node);
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct {
    tree_t **node;
    int rear;
    int front;
    int size;
    int capacity;
} Queue;

Queue *createQueue(int n) {
    Queue *head = malloc(sizeof(Queue));
    if (!head) return NULL;

    head->node = malloc(n * sizeof(tree_t *));
    if (!head->node) {
        free(head);
        return NULL;
    }

    head->front = 0;
    head->rear = 0;
    head->size = 0;
    head->capacity = n;
    return head;
}

int isEmptyQueue(Queue *head) {
    if (!head) return 1;
    return head->size == 0;
}

int isFullQueue(Queue *head) {
    if (!head) return 0;
    return head->size == head->capacity;
}

void enqueue(Queue *head, tree_t *node) {
    if (!head || isFullQueue(head)) return;
    head->node[head->rear++] = node;
    head->size++;
}

tree_t *dequeue(Queue *head) {
    if (!head || isEmptyQueue(head)) return NULL;
    head->size--;
    return head->node[head->front++];
}

void freeQueue(Queue *head) {
    if (!head) return;
    free(head->node);
    free(head);
}

void freeTree(tree_t *tree) {
    if (!tree) return;
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree->string);
    free(tree);
}

tree_t *fill(tree_t *root, char *s) {
    if (!root)
        return createTree(s);

    Queue *queue = createQueue(100);
    if (!queue) return root;

    tree_t *newNode = createTree(s);
    if (!newNode) {
        freeQueue(queue);
        return root;
    }

    enqueue(queue, root);

    while (!isEmptyQueue(queue)) {
        tree_t *node = dequeue(queue);

        if (!node->left) {
            node->left = newNode;
            freeQueue(queue);
            return root;
        }

        enqueue(queue, node->left);

        if (!node->right) {
            node->right = newNode;
            freeQueue(queue);
            return root;
        }

        enqueue(queue, node->right);
    }

    freeQueue(queue);
    return root;
}
