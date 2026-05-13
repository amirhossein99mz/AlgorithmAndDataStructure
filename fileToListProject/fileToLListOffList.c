#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef  struct list2_t {
    int data;
    struct list2_t *next;
}list2_t;

list2_t* create_list2(int key) {
    list2_t* node = (list2_t*)malloc(sizeof(list2_t));
    if ( !node ) return NULL;
    node->data = key;
    node->next = NULL;
    return node;
}

list2_t *addNode(list2_t *head,list2_t *node) {

    if (!head  || strcmp(node->string,head->string)<0) {
        node->next = head;
        return node;
    }

    if(!(strcmp(node->string,head->string)))return head;

    if(head->next && strcmp(node->string,head->next->string)>0){
        head->next = addNode(head->next,node);
        return head;
    }

    node->next = head->next;
    head->next = node;

    return head;
}

void free_list2(list2_t* node) {
    if ( !node ) return;
    list2_t* temp = node;
    while (temp) {
        list2_t* next = temp->next;
        free(temp);
        temp = next;
    }
}

typedef  struct list1_t {
    char *string;
    list2_t *numbers;
    struct list1_t *next;
}list1_t;

list1_t* create_list1(char *string) {
    list1_t* node = malloc(sizeof(list1_t));
    if ( !node ) return NULL;
    node->string = strdup(string);
    if (!node->string) return NULL;
    node->numbers = NULL;
    node->next = NULL;
    return node;
}

list1_t *addNode1(list1_t *head,list1_t *node) {
    if(!head)  return node;



    if(!(strcmp(node->string,head->string))){

            for (list2_t *temp = node->numbers;temp;temp = temp->next) {

                list2_t *newNode =create_list2(temp->data);

                head->numbers =addNode(head->numbers,newNode);}

            free_list2(node->numbers);
            free(node->string);
            free(node);

            return head;

     }

    if(head->next && strcmp(node->string,head->next->string)>0){
        head->next = addNode(head->next,node);
        return head;
    }

    node->next = head->next;
    head->next = node;

    return head;
}

void free_list1(list1_t* node) {
    if ( !node ) return;
    list1_t *temp = node;
    while (temp) {
        list1_t *next = temp->next;
        free(temp->string);
        free_list2(temp->numbers);
        free(temp);
        temp = next;
    }
}

list1_t *file_to_list_of_lists(char *name) {

    if (!name)return NULL;

    FILE *fp = fopen(name,"r");
    if (!fp)return  NULL;

    char buffer[100];
    int count;

    list1_t *head1 = NULL;

    while (fscanf(fp,"%s %d",buffer,&count)==2) {

        list1_t *node = create_list1(buffer);
        list2_t *head2 = NULL;

        for (int i=0;i<count;i++) {
            int data;
            fscanf(fp,"%d",&data);

            list2_t* node2 = create_list2(data);
            head2 = addNode(head2,node2);
        }

        node->numbers = head2;
        head1 = addNode1(head1,node);
    }

    fclose(fp);
    return head1;
}
