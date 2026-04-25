
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list2_t {
    int data;
    struct list2_t *next;
} list2_t;

typedef struct list1_t {
    char *str;
    list2_t *numbers;
    struct list1_t *next;
} list1_t;

// create node for secondary list
list2_t *createList2(int value) {
    list2_t *node = malloc(sizeof(list2_t));
    node->data = value;
    node->next = NULL;
    return node;
}

// insert unique value into secondary list
void insert_unique_list2(list2_t **head, int value) {
    for (list2_t *t = *head; t; t = t->next)
        if (t->data == value) return;

    list2_t *node = createList2(value);
    node->next = *head;
    *head = node;
}

// find or create primary node
list1_t *find_or_create(list1_t **head, char *str) {
    for (list1_t *t = *head; t; t = t->next)
        if (strcmp(t->str, str) == 0)
            return t;

    list1_t *node = malloc(sizeof(list1_t));
    node->str = strdup(str);
    node->numbers = NULL;
    node->next = *head;
    *head = node;
    return node;
}

list1_t *file_to_list_of_lists(char *name) {
    FILE *fp = fopen(name, "r");
    if (!fp) return NULL;

    list1_t *head = NULL;
    char str[128];
    int count;

    while (fscanf(fp, "%s %d", str, &count) == 2) {
        list1_t *p = find_or_create(&head, str);

        for (int i = 0; i < count; i++) {
            int x;
            fscanf(fp, "%d", &x);
            insert_unique_list2(&p->numbers, x);
        }
    }

    fclose(fp);
    return head;
}

// print result (for testing)
void print_lists(list1_t *head) {
    for (list1_t *t = head; t; t = t->next) {
        printf("%s: ", t->str);
        for (list2_t *n = t->numbers; n; n = n->next)
            printf("%d ", n->data);
        printf("\n");
    }
}

// free memory
void free_all(list1_t *head) {
    while (head) {
        list1_t *tmp = head;
        free(tmp->str);

        list2_t *n = tmp->numbers;
        while (n) {
            list2_t *nn = n;
            n = n->next;
            free(nn);
        }

        head = head->next;
        free(tmp);
    }
}

// simple main for demo
int main() {
    list1_t *res = file_to_list_of_lists("input.txt");
    print_lists(res);
    free_all(res);
    return 0;
}
