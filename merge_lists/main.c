
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listB_t {
    char *string;
    struct listB_t *next;
} listB_t;

typedef struct listA_t {
    listB_t *strings;
    struct listA_t *next;
} listA_t;

listB_t *createB(char *s) {
    listB_t *n = malloc(sizeof(listB_t));
    n->string = strdup(s);
    n->next = NULL;
    return n;
}

int exists(listB_t *head, char *s) {
    while (head) {
        if (strcmp(head->string, s) == 0) return 1;
        head = head->next;
    }
    return 0;
}

listB_t *insert_sorted_unique(listB_t *head, char *s) {
    if (exists(head, s)) return head;

    listB_t *n = createB(s);

    if (!head || strcmp(s, head->string) < 0) {
        n->next = head;
        return n;
    }

    listB_t *cur = head;
    while (cur->next && strcmp(cur->next->string, s) < 0)
        cur = cur->next;

    n->next = cur->next;
    cur->next = n;

    return head;
}

listB_t *merge(listA_t *head) {
    listB_t *result = NULL;

    for (listA_t *a = head; a; a = a->next) {
        for (listB_t *b = a->strings; b; b = b->next) {
            result = insert_sorted_unique(result, b->string);
        }
    }

    return result;
}

void print(listB_t *h) {
    while (h) {
        printf("%s ", h->string);
        h = h->next;
    }
    printf("\n");
}

int main() {
    // sample test
    listB_t *l1 = createB("apple");
    l1->next = createB("banana");

    listB_t *l2 = createB("banana");
    l2->next = createB("cherry");

    listA_t a2 = {l2, NULL};
    listA_t a1 = {l1, &a2};

    listB_t *res = merge(&a1);
    print(res);

    return 0;
}
