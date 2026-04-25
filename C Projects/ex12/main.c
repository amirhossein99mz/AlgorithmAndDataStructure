#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ──────────────────────────────────────────────
 * list_2 : secondary linked list storing integers
 * ────────────────────────────────────────────── */
typedef struct list_2 {
    int data;
    struct list_2 *next;
} list_2;

list_2 *createList2(int key) {
    list_2 *newList = (list_2 *)malloc(sizeof(list_2));
    if (!newList) return NULL;
    newList->data = key;
    newList->next = NULL;
    return newList;
}

void freeList2(list_2 *list) {
    if (!list) return;
    list_2 *temp = list;
    while (temp) {
        list_2 *next = temp->next;
        free(temp);
        temp = next;
    }
}

/* ──────────────────────────────────────────────
 * list_1 : primary linked list storing strings
 *          each node owns a list_2 of integers
 * ────────────────────────────────────────────── */
typedef struct list_1 {
    char    *string;
    list_2  *numbers;
    struct list_1 *next;
} list_1;

list_1 *createList1(char *str, list_2 *nums) {
    list_1 *newList = (list_1 *)malloc(sizeof(list_2));
    if (!newList || !str || !nums) return NULL;
    newList->string  = strdup(str);
    newList->next    = NULL;
    newList->numbers = nums;
    return newList;
}

void freeList1(list_1 *list) {
    if (!list) return;
    list_1 *temp = list;
    while (temp) {
        list_1 *next = temp->next;
        free(temp->string);
        free(temp->numbers);
        free(temp);
        temp = next;
    }
}

/* ──────────────────────────────────────────────
 * insertt : inserts a list_1 node into the list,
 *           merging integer lists if strings match
 * ────────────────────────────────────────────── */
list_1 *insertt(list_1 *head, list_1 *node) {
    if (!node) return head;
    if (!head) { node->next = NULL; return node; }

    int cmp = strcmp(head->string, node->string);

    if (cmp == 0) {
        // Same string: append integer node to secondary list
        list_2 *cur = head->numbers;
        if (!cur) {
            head->numbers = node->numbers;
            return head;
        }
        while (cur->next) cur = cur->next;
        cur->next = node->numbers;
        return head;
    }

    // Insert before head (alphabetically earlier)
    if (cmp > 0) { node->next = head; return node; }

    // Move forward (recursive)
    head->next = insertt(head->next, node);
    return head;
}

/* ──────────────────────────────────────────────
 * insert_ : reads file and builds the full structure
 * ────────────────────────────────────────────── */
list_1 *insert_(char *name) {
    FILE *fp = fopen(name, "r");
    if (!fp) return NULL;

    list_1 *head = NULL;
    int data; char line[100];

    while (fscanf(fp, "%s %d", line, &data) == 2) {
        list_2 *node2 = createList2(data);
        list_1 *node1 = createList1(line, node2);
        head = insertt(head, node1);
    }
    fclose(fp);
    return head;
}

/* ──────────────────────────────────────────────
 * print helper
 * ────────────────────────────────────────────── */
void printList(list_1 *head) {
    while (head) {
        printf("[%s] -> ", head->string);
        list_2 *cur = head->numbers;
        while (cur) {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a small demo input file
    FILE *f = fopen("input.txt", "w");
    fprintf(f, "ALFONSO 13\nMARIA 15\nCLARA 12\nRAFFAELA 33\nALFONSO 12\nCLARA 12\nRAFFAELA 33\nCLARA 12\n");
    fclose(f);

    list_1 *result = insert_("input.txt");
    printf("Resulting list of lists:\n");
    printList(result);

    freeList1(result);
    return 0;
}
