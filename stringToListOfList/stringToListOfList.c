#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node_t {
    char *string;
    struct node_t *next;
    struct node_t *prev;
} node_t;

node_t *create_node(char *string) {

    node_t *node = malloc(sizeof(node_t));

    if (!node) return NULL;

    node->string = strdup(string);

    node->next = NULL;
    node->prev = NULL;

    return node;
}

void free_node_circular(node_t *head) {

    if (!head) return;

    node_t *temp = head->next;

    while (temp != head) {

        node_t *next = temp->next;

        free(temp->string);
        free(temp);

        temp = next;
    }

    free(head->string);
    free(head);
}

void string_to_fifo(char *s, node_t **letter, node_t **digit) {

    if (!s || !letter || !digit) return;

    node_t *head_letter = NULL;
    node_t *tail_letter = NULL;

    node_t *head_digit = NULL;
    node_t *tail_digit = NULL;

    for (int i = 0; s[i]; i++) {

        if (isdigit(s[i])) {

            char buffer[100];
            int index = 0;

            while (isdigit(s[i])) {
                buffer[index++] = s[i++];
            }

            buffer[index] = '\0';

            node_t *node = create_node(buffer);

            if (!head_digit) {
                head_digit = tail_digit = node;
            }
            else {
                tail_digit->next = node;
                node->prev = tail_digit;
                tail_digit = node;
            }

            i--;
        }

        else if (isalpha(s[i])) {

            char buffer[100];
            int index = 0;

            while (isalpha(s[i])) {
                buffer[index++] = s[i++];
            }

            buffer[index] = '\0';

            node_t *node = create_node(buffer);

            if (!head_letter) {
                head_letter = tail_letter = node;
            }
            else {
                tail_letter->next = node;
                node->prev = tail_letter;
                tail_letter = node;
            }

            i--;
        }
    }

    if (head_letter) {
        head_letter->prev = tail_letter;
        tail_letter->next = head_letter;
    }

    if (head_digit) {
        head_digit->prev = tail_digit;
        tail_digit->next = head_digit;
    }

    *letter = head_letter;
    *digit = head_digit;
}

void printt(node_t *letter, node_t *digit) {

    if (letter) {

        printf("LETTER LIST:\\n");

        node_t *temp = letter;

        do {
            printf("%s ", temp->string);
            temp = temp->next;
        } while (temp != letter);

        printf("\\n");
    }

    if (digit) {

        printf("DIGIT LIST:\\n");

        node_t *temp = digit;

        do {
            printf("%s ", temp->string);
            temp = temp->next;
        } while (temp != digit);

        printf("\\n");
    }
}

int main() {

    char s[] = "abc1234xyz233fgew";

    node_t *letter = NULL;
    node_t *digit = NULL;

    string_to_fifo(s, &letter, &digit);

    printt(letter, digit);

    free_node_circular(letter);
    free_node_circular(digit);

    return 0;
}
