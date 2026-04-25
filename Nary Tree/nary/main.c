#include <stdio.h>
#include <stdlib.h>

/* ──────────────────────────────────────────────
 * node_t : n-ary tree node
 *   data            - integer key
 *   children        - dynamic array of child pointers
 *   children_length - number of children
 * ────────────────────────────────────────────── */
typedef struct node_t {
    int data;
    struct node_t **children;
    int children_length;
} node_t;

node_t *create_node(int data, int children_length) {
    node_t *newNode = malloc(sizeof(node_t));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->children = malloc(children_length * sizeof(node_t *));
    if (!newNode->children) return NULL;
    for (int i = 0; i < children_length; i++) newNode->children[i] = NULL;
    newNode->children_length = children_length;
    return newNode;
}

void free_node(node_t *node) {
    if (!node) return;
    for (int i = 0; i < node->children_length; i++) free(node->children[i]);
    free(node->children);
    free(node);
}

/* ──────────────────────────────────────────────
 * Queue : circular array-based queue of node_t*
 *   used for BFS level-by-level traversal
 * ────────────────────────────────────────────── */
typedef struct {
    node_t **numbers;
    int rear;
    int front;
    int size;
    int capacity;
} Queue;

Queue *queue_create(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) return NULL;
    queue->numbers = malloc(capacity * sizeof(node_t *));
    if (!queue->numbers) return NULL;
    queue->rear = queue->front = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

void equeue(Queue *queue, node_t *node) {
    if (queue->size == queue->capacity) return;
    queue->numbers[queue->rear++] = node;
    queue->size++;
}

node_t *dequeue(Queue *queue) {
    if (queue->size == 0 || queue->rear == queue->front) return NULL;
    node_t *node = queue->numbers[queue->front++];
    queue->size--;
    return node;
}

/* ──────────────────────────────────────────────
 * display_crowded_depth:
 *   BFS level by level. Tracks the depth with the
 *   most nodes. Prints all keys at that depth and
 *   returns the depth value.
 * ────────────────────────────────────────────── */
int display_crowded_depth(node_t *root) {
    if (!root) return 0;

    Queue *queue = queue_create(100);

    int max        = -1;
    int depth      = 0;
    int best_depth = 0;

    equeue(queue, root);   // seed BFS with root

    while (!isEmpty(queue)) {
        int size = queue->size;
        node_t *arr[size];

        // Dequeue all nodes at current depth, enqueue their children
        for (int i = 0; i < size; i++) {
            node_t *node = dequeue(queue);
            arr[i] = node;
            for (int j = 0; j < node->children_length; j++) {
                if (node->children) equeue(queue, node->children[j]);
            }
        }

        // Track the deepest level with the most nodes
        if (size > max) {
            max        = size;
            best_depth = depth;
            for (int i = 0; i < size; i++) printf("%d ", arr[i]->data);
            printf("\n");
        }
        depth++;
    }
    return best_depth;
}

/* ──────────────────────────────────────────────
 * Demo main: builds a sample n-ary tree and runs
 * ────────────────────────────────────────────── */
int main() {
    /*
     * Sample tree:
     *           10
     *         / | \
     *        2  3   8
     *       /|     /|\
     *      1  5  12  7  4
     */
    node_t *root = create_node(10, 3);
    root->children[0] = create_node(2,  2);
    root->children[1] = create_node(3,  0);
    root->children[2] = create_node(8,  3);

    root->children[0]->children[0] = create_node(1,  0);
    root->children[0]->children[1] = create_node(5,  0);
    root->children[2]->children[0] = create_node(12, 0);
    root->children[2]->children[1] = create_node(7,  0);
    root->children[2]->children[2] = create_node(4,  0);

    printf("Most crowded depth keys: ");
    int d = display_crowded_depth(root);
    printf("Most crowded depth: %d\n", d);

    return 0;
}
