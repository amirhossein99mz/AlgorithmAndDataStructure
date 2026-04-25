#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----------- TREE STRUCT ----------- */
typedef struct tree_t {
    char *string;
    struct tree_t *left;
    struct tree_t *right;
} tree_t;

/* Create node */
tree_t *create_node(char *s) {
    tree_t *node = malloc(sizeof(tree_t));
    if (!node) return NULL;

    node->string = strdup(s);
    node->left = node->right = NULL;

    return node;
}

/* ----------- QUEUE (for BFS) ----------- */
typedef struct qnode {
    tree_t *node;
    struct qnode *next;
} qnode;

void enqueue(qnode **head, qnode **tail, tree_t *node) {
    qnode *new = malloc(sizeof(qnode));
    new->node = node;
    new->next = NULL;

    if (*tail) (*tail)->next = new;
    else *head = new;

    *tail = new;
}

tree_t *dequeue(qnode **head, qnode **tail) {
    if (!*head) return NULL;

    qnode *tmp = *head;
    tree_t *node = tmp->node;

    *head = tmp->next;
    if (!*head) *tail = NULL;

    free(tmp);
    return node;
}

/* ----------- FILL FUNCTION ----------- */
tree_t *fill(tree_t *root, char *s) {
    tree_t *new_node = create_node(s);
    if (!new_node) return root;

    if (!root) return new_node;

    qnode *head = NULL, *tail = NULL;
    enqueue(&head, &tail, root);

    while (head) {
        tree_t *curr = dequeue(&head, &tail);

        if (!curr->left) {
            curr->left = new_node;
            break;
        } else {
            enqueue(&head, &tail, curr->left);
        }

        if (!curr->right) {
            curr->right = new_node;
            break;
        } else {
            enqueue(&head, &tail, curr->right);
        }
    }

    return root;
}

/* ----------- TEST (optional) ----------- */
void print_level_order(tree_t *root) {
    if (!root) return;

    qnode *head = NULL, *tail = NULL;
    enqueue(&head, &tail, root);

    while (head) {
        tree_t *curr = dequeue(&head, &tail);
        printf("%s ", curr->string);

        if (curr->left) enqueue(&head, &tail, curr->left);
        if (curr->right) enqueue(&head, &tail, curr->right);
    }
}

int main() {
    tree_t *root = NULL;

    root = fill(root, "A");
    root = fill(root, "B");
    root = fill(root, "C");
    root = fill(root, "D");
    root = fill(root, "E");

    print_level_order(root);
    printf("\n");

    return 0;
}
