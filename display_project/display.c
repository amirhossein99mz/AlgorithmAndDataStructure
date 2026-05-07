
#include <stdio.h>
#include <stdlib.h>

typedef  struct node_t {
    int data;
    int capacity;
    struct node_t **children;
}node_t;

node_t *createNode(int data,int capacity) {
    node_t *newNode = malloc(sizeof(node_t));
    if (!newNode)return NULL;
    newNode->data = data;
    newNode->capacity = capacity;
    newNode->children = malloc(capacity*sizeof(node_t *));
    if (!newNode->children)return NULL;
    for (int i = 0; i < capacity; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void freeNode(node_t *root) {
    if (!root)return;
    node_t *temp = root;
    for (int i = 0; i < temp->capacity; i++) {
        if (temp->children[i])freeNode(temp->children[i]);
    }
    free(temp->children);
    free(temp);
}

typedef  struct {
    node_t **nodes;
    int rear;
    int front;
    int capacity;
    int size;
}Queue;

Queue *createQueue(int size) {
    if (!size)return NULL;
    Queue *pQ = malloc(sizeof(Queue ));
    if (!pQ)return NULL;
    pQ->rear = 0;
    pQ->front = 0;
    pQ->capacity = size;
    pQ->size = 0;
    pQ->nodes = malloc(pQ->capacity*sizeof(node_t *));
    if (!pQ->nodes)return NULL;
    for (int i = 0; i < size; i++) pQ->nodes[i] = NULL;
    return pQ;
}

int isEmpty(Queue *queue) {
    if (!queue)return 0;
    return queue->rear == queue->front;
}

int isFull(Queue *queue) {
    if (!queue)return 0;
    return queue->capacity == queue->rear;
}

void equeue(Queue *queue,node_t *node) {
    if (!queue)return;
    queue->size++;
    queue->nodes[queue->rear++] = node;
}

node_t *dequeue(Queue *queue) {
    if (!queue || isEmpty(queue))return NULL;
    queue->size--;
    return queue->nodes[queue->front++];
}


void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int *arr,int left,int right) {
    int i = left-1;
    int j = right;
    int pivot =arr[right];

    while (i<j) {
        while (arr[++i]<pivot);
        while (arr[--j]>=pivot && j>left);
        if (i<j) {
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i],&arr[right]);
    return i;
}

void quickSort(int *arr,int left,int right) {
    if (left>=right) return;

    int p = partition(arr,left,right);

    quickSort(arr,left,p-1);
    quickSort(arr,p+1,right);
}

void display(node_t *root) {

    if (!root)return;

    Queue *queue = createQueue(100);

    equeue(queue,root);

    while (!isEmpty(queue)) {

        int size = queue->size;

        int arr[size];

        for (int i = 0; i < size; i++) {

            node_t *node = dequeue(queue);

            arr[i] = node->data;

            if (node->children) {

                for (int j=0;j<node->capacity;j++) {

                    if (node->children[j]) {

                        equeue(queue,node->children[j]);
                    }
                }
            }
        }

        quickSort(arr,0,size - 1);

        for (int i = 0; i < size; i++) {

            printf("%d ",arr[i]);
        }

        printf("- ");
    }
}
