#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    int size;
    struct node_t **children;
}node_t;

node_t *create_node(int data,int n) {

    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;

    node->data = data;
    node->size = n;

    node->children = malloc(n*sizeof(node_t *));

    if (!node->children)
        return NULL;

    for (int i=0;i<n;i++)
        node->children[i] = NULL;

    return node;
}

void free_node(node_t *node) {

    if (!node)
        return;

    for (int i=0;i<node->size;i++)
        free(node->children[i]);

    free(node->children);
    free(node);
}

typedef struct {

    node_t **numbers;

    int front;
    int rear;

    int size;
    int capacity;

}Queue;

Queue *create_queue(int n) {

    Queue *q = malloc(sizeof(Queue));

    if (!q)
        return NULL;

    q->numbers = malloc(n*sizeof(node_t *));

    if (!q->numbers)
        return NULL;

    q->capacity = n;

    q->front = 0;
    q->rear = 0;

    q->size = 0;

    return q;
}

int isEmpty(Queue *q) {

    if (!q)
        return -1;

    return q->front == q->rear;
}

int isFull(Queue *q) {

    if (!q)
        return -1;

    return q->capacity == q->size;
}

void enqueue(Queue *q,node_t *n) {

    if (!q || !n)
        return;

    q->size++;

    q->numbers[q->rear++] = n;
}

node_t *dequeue(Queue *q) {

    if (!q || isEmpty(q))
        return NULL;

    q->size--;

    return q->numbers[q->front++];
}

int display_crowded_depth(node_t *root) {

    if (!root)
        return 0;

    Queue *queue = create_queue(100);

    enqueue(queue,root);

    int max_size = -1;
    int max_depth = -1;

    int depth = 0;

    while (!isEmpty(queue)) {

        int size = queue->size;

        if (size > max_size) {
            max_size = size;
            max_depth = depth;
        }

        for (int i=0;i<size;i++) {

            node_t *newNode = dequeue(queue);

            if (!newNode)
                return -1;

            if (depth == max_depth)
                printf("%d ",newNode->data);

            if (newNode->children) {

                for (int j=0;j<newNode->size;j++) {

                    if (newNode->children[j]) {
                        enqueue(queue,newNode->children[j]);
                    }
                }
            }
        }

        depth++;
    }

    return max_depth;
}

int main() {

    node_t *root = create_node(17,3);

    root->children[0] = create_node(22,2);
    root->children[1] = create_node(2,1);
    root->children[2] = create_node(31,2);

    root->children[0]->children[0] = create_node(1,1);
    root->children[0]->children[1] = create_node(5,0);

    root->children[1]->children[0] = create_node(12,0);

    root->children[2]->children[0] = create_node(7,1);
    root->children[2]->children[1] = create_node(4,1);

    root->children[0]->children[0]->children[0] = create_node(9,0);

    root->children[2]->children[0]->children[0] = create_node(3,0);

    root->children[2]->children[1]->children[0] = create_node(15,0);

    printf("\nDepth = %d\n",display_crowded_depth(root));

    free_node(root);

    return 0;
}
