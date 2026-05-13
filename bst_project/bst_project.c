#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list {
    int number;
    struct list *next;
} list;

list *createList(int data) {

    list *newNode = malloc(sizeof(list));

    if (!newNode) return NULL;

    newNode->number = data;
    newNode->next = NULL;

    return newNode;
}

list *addNode(list *head, list *node) {

    // if number is smaller
    if (!head || node->number < head->number) {
        node->next = head;
        return node;
    }

    //if numner is equal
    if(head->number == node -> number)return head;
    //insert 2 in 1->10 now head is 1 : so below is skip
    if(head->next && node->number > head->next->number){
        head->next = addNode(head->next, node);//if 20 in 1->10 : it goes to next one
        return head;
    }
    // now we are here 2->10 and then 1->2->10
    node->next = head->next;
    head->next = node;
    return head;
}

void freeList(list *head) {

    list *temp = head;

    while (temp) {
        list *next = temp->next;
        free(temp);
        temp = next;
    }
}

typedef struct bst_s {
    char *string;
    list *pointer_to_first_number;
    struct bst_s *left;
    struct bst_s *right;
} bst_t;

bst_t *createBST(char *str) {

    if (!str) return NULL;

    bst_t *newNode = malloc(sizeof(bst_t));

    if (!newNode) return NULL;

    newNode->string = strdup(str);

    if (!newNode->string) {
        free(newNode);
        return NULL;
    }

    newNode->pointer_to_first_number = NULL;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bst_t *insertBST(bst_t *head, bst_t *node) {

    if (!head) return node;

    int cmp = strcmp(node->string, head->string);

    if (cmp > 0) {

        head->right = insertBST(head->right, node);
    }

    else if (cmp < 0) {

        head->left = insertBST(head->left, node);
    }

    else {

        for(list *tempList = node->pointer_to_first_number;tempList;tempList = tempList->next){
            list *newNode = createList(tempList->number);
            if (!newNode) break;
            head->pointer_to_first_number =addNode(head->pointer_to_first_number, newNode);

        }

        freeList(node->pointer_to_first_number);
        free(node->string);
        free(node);
    }

    return head;
}

void freeBST(bst_t *root) {

    if (!root) return;

    freeBST(root->left);
    freeBST(root->right);

    free(root->string);
    freeList(root->pointer_to_first_number);

    free(root);
}

bst_t *file_to_bst_of_lists(char *name) {

    if (!name) return NULL;

    FILE *fp = fopen(name, "r");

    if (!fp) {
        fprintf(stderr, "File %s does not exist.\n", name);
        return NULL;
    }

    char buffer[101];
    int count;

    bst_t *headBST = NULL;

    while (fscanf(fp, "%100s %d", buffer, &count) == 2) {

        bst_t *newBST = createBST(buffer);

        if (!newBST) continue;

        list *headList = NULL;

        for (int i = 0; i < count; i++) {

            int data;

            if (fscanf(fp, "%d", &data) != 1)
                break;

            list *newNode = createList(data);

            if (!newNode) continue;

            headList = addNode(headList, newNode);
        }

        newBST->pointer_to_first_number = headList;

        headBST = insertBST(headBST, newBST);
    }

    fclose(fp);

    return headBST;
}
