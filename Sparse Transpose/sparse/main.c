#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ──────────────────────────────────────────────
 * list_t2 : secondary list node
 *   value     - the non-zero element value
 *   col_index - column position in the matrix
 *   next      - pointer to the next element in the same row
 * ────────────────────────────────────────────── */
typedef struct list_t2 {
    int value;
    int col_index;
    struct list_t2 *next;
} list_t2;

list_t2 *create(int key) {
    list_t2 *head = malloc(sizeof(list_t2));
    if (!head) return NULL;
    head->value     = key;
    head->col_index = 0;
    head->next      = NULL;
    return head;
}

/* insert: inserts key into list_t2 in sorted order by value */
list_t2 *insert(list_t2 *head, int key) {

    if (!head) return create(key);             // 1. head is NULL

    if (head->value > key) {                   // 2. Insert before head
        list_t2 *newNode = create(key);
        newNode->next = head;
        head = newNode;
        return head;
    }

    list_t2 *temp = head;
    while (temp->next) {
        if (temp->value == key) return head;

        // insert 2 in 1->3 where temp is 1
        if (temp->next->value > key && temp->value < key) {
            list_t2 *newNode  = create(key);
            newNode->next     = temp->next;    // 2->3
            temp->next        = newNode;       // 1->2->3
            return head;
        }
        temp = temp->next;                     // move forward
    }

    if (temp->value != key) {                  // insert at end
        temp->next = create(key);
    }
    return head;
}

void free_list2(list_t2 *head) {
    list_t2 *temp = head;                      // line cut off in original
    while (temp) {
        list_t2 *next = temp->next;
        free(temp);
        temp = next;
    }
}

/* ──────────────────────────────────────────────
 * list_t1 : primary list node
 *   row_index - row position in the matrix
 *   lists     - pointer to the secondary list (list_t2)
 *   next      - pointer to the next row node
 * ────────────────────────────────────────────── */
typedef struct list_t1 {
    int       row_index;
    list_t2  *lists;
    struct list_t1 *next;
} list_t1;

list_t1 *createList1(list_t2 *head) {
    if (!head) return NULL;
    list_t1 *head1 = malloc(sizeof(list_t1));
    if (!head1) return NULL;
    head1->lists     = head;
    head1->row_index = 0;
    head1->next      = NULL;
    return head1;
}

void free_list1(list_t1 *head) {
    if (!head) return;
    list_t1 *temp = head;
    while (temp) {
        list_t1 *next = temp->next;
        free_list2(temp->lists);
        free(temp);
        temp = next;
    }
}

/* ──────────────────────────────────────────────
 * transpose: converts sparse list-of-lists into
 * its transposed form stored in *head2.
 * Strategy:
 *   1. Expand the sparse list into a dense 100x100
 *      matrix (initialised to -1 = "empty").
 *   2. Re-build the list-of-lists from mat[i][j]
 *      reading columns as rows (swap i and j).
 * ────────────────────────────────────────────── */
void transpose(list_t1 *head, list_t1 **head2) {
    if (!head || !head2) return;

    int mat[100][100];
    memset(mat, -1, sizeof(mat));              // fill all with -1 (not just first element)

    // Step 1: expand sparse structure into dense matrix
    for (list_t1 *temp = head; temp; temp = temp->next) {
        for (list_t2 *temp2 = temp->lists; temp2; temp2 = temp2->next) {
            int row = temp->row_index;
            int col = temp2->col_index;
            mat[row][col] = temp2->value;
        }
    }

    // Step 2: build transposed sparse structure
    *head2 = NULL;
    for (int i = 0; i < 100; i++) {
        list_t1 *row = NULL;
        for (int j = 0; j < 100; j++) {
            if (mat[i][j] != -1) {
                if (!row) {
                    row = malloc(sizeof(list_t1));
                    row->lists     = NULL;
                    row->row_index = i;
                    row->next      = *head2;
                    *head2         = row;
                }
                list_t2 *col = create(mat[j][i]);
                if (!col) return;
                col->next  = row->lists;
                row->lists = col;
            }
        }
    }
}

/* ──────────────────────────────────────────────
 * Helpers: print the sparse structure
 * ────────────────────────────────────────────── */
void printSparse(list_t1 *head) {
    for (list_t1 *r = head; r; r = r->next) {
        printf("Row %d: ", r->row_index);
        for (list_t2 *c = r->lists; c; c = c->next)
            printf("[col=%d val=%d] ", c->col_index, c->value);
        printf("\n");
    }
}

int main() {
    /*
     * Build sparse matrix:
     *   row 0: (col 1, val 5), (col 2, val 6)
     *   row 2: (col 1, val 3), (col 3, val 9)
     */
    list_t1 *head1 = NULL;

    // Row 0
    list_t2 *r0 = create(5); r0->col_index = 1;
    list_t2 *r0b = create(6); r0b->col_index = 2; r0->next = r0b;
    list_t1 *n0 = createList1(r0); n0->row_index = 0;
    head1 = n0;

    // Row 2
    list_t2 *r2 = create(3); r2->col_index = 1;
    list_t2 *r2b = create(9); r2b->col_index = 3; r2->next = r2b;
    list_t1 *n2 = createList1(r2); n2->row_index = 2;
    n0->next = n2;

    printf("Original sparse matrix:\n");
    printSparse(head1);

    list_t1 *head2 = NULL;
    transpose(head1, &head2);

    printf("\nTransposed sparse matrix:\n");
    printSparse(head2);

    free_list1(head1);
    free_list1(head2);
    return 0;
}
