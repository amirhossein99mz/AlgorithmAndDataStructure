#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ──────────────────────────────────────────────
 * node_t : doubly-linked circular list node
 *   string - heap-allocated substring (letters or digits)
 *   prev   - pointer to previous node (circular)
 *   next   - pointer to next node (circular)
 * ────────────────────────────────────────────── */
typedef struct node_t {
    char          *string;
    struct node_t *prev;
    struct node_t *next;
} node_t;

node_t *create_node(char *string) {
    node_t *node    = malloc(sizeof(node_t));
    node->string    = strdup(string);
    node->prev = node->next = NULL;
    return node;
}

/* ──────────────────────────────────────────────
 * insert_into_circular_linked_list:
 *   appends node to the tail of a circular doubly-
 *   linked list. *head points to the head (oldest
 *   element), so appending to tail implements FIFO.
 * ────────────────────────────────────────────── */
void insert_into_circular_linked_list(node_t **head, node_t *node) {

    if (!*head) {                          // empty list: node points to itself
        node->prev = node->next = node;
        *head = node;
        return;
    }

    node_t *temp = *head;
    node_t *prev = NULL;
    // Walk until we reach the last node (its next == *head in a circular list)
    while (temp->next != *head) {         // fixed: original used while(temp) which loops forever
        prev = temp;
        temp = temp->next;
    }
    if (prev) node->prev = temp;
    temp->next        = node;             // last->next = new node
    node->next        = *head;            // new node wraps back to head
    (*head)->prev     = node;             // head's prev = new node
}

/* ──────────────────────────────────────────────
 * string_to_fifo:
 *   walks string s character by character.
 *   Consecutive letters are collected into one node
 *   and appended to the 'letter' circular FIFO.
 *   Consecutive digits are collected into one node
 *   and appended to the 'digit' circular FIFO.
 * ────────────────────────────────────────────── */
void string_to_fifo(char *s, node_t **letter, node_t **digit) {

    while (*s) {
        char buffer[100];
        int  count;

        if (isalpha(*s)) {
            count = 0;
            while (isalpha(*s)) buffer[count++] = *s++;   // fixed: original missing s++
            buffer[count] = '\0';
            node_t *newLetterNode = create_node(buffer);
            insert_into_circular_linked_list(letter, newLetterNode);
        }

        // buffer[count]='\0': terminate buffer; in the future we use a new one.
        if (isdigit(*s)) {
            count = 0;
            while (isdigit(*s)) buffer[count++] = *s++;   // fixed: original missing s++
            buffer[count] = '\0';
            node_t *newDigitNode = create_node(buffer);
            insert_into_circular_linked_list(digit, newDigitNode);  // fixed: original passed 'letter' instead of 'digit'
        }
    }
}

/* ──────────────────────────────────────────────
 * Helper: print a circular FIFO list
 * ────────────────────────────────────────────── */
void print_circular(node_t *head, const char *name) {
    if (!head) { printf("%s: (empty)\n", name); return; }
    printf("%s: ", name);
    node_t *cur = head;
    do {
        printf("[%s] -> ", cur->string);
        cur = cur->next;
    } while (cur != head);
    printf("(back to head)\n");
}

int main() {
    char *s = "abc12345xyz333fgew";

    node_t *letter = NULL;
    node_t *digit  = NULL;

    string_to_fifo(s, &letter, &digit);

    print_circular(letter, "letter");
    print_circular(digit,  "digit ");

    return 0;
}
