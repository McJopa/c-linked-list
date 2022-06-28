#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct list {
    int length;
    struct node* head;
    int (*data_compare)(void *v1, void *v2);
    void (*data_printer)(void *data);
    void (*data_free)(void *data);
};

struct node {
    void* data;
    struct node* next;
};

struct list* list_create(int (*data_compare)(void *v1, void* v2), void (*data_printer)(void *data), void (*data_free)(void *data)){
    struct list *list = (struct list*)malloc(sizeof(struct list));
    list->head = NULL;
    list->data_compare = data_compare;
    list->data_printer = data_printer;
    list->data_free = data_free;
    return list;
}

struct node* node_create(void * data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->next = NULL;
    n->data = data;
    return n;
}

int list_length(struct list *list){
    struct node *temp = list->head;
    int length = 0;
    while (temp != NULL)  {
        length++;
        temp = temp->next;
    }
    return length;
}

void list_print(struct list* list){
    struct node* temp = list->head;
    while(temp != NULL){
        list->data_printer(temp->data);
        if (temp->next != NULL) printf("->");
        temp = temp->next;
    }
    printf("\n");
}

int list_prepend(struct list* list, void *data){
    return 0;   
}

int list_append(struct list* list, void *data){
    struct node *n = node_create(data);
    if (list->head == NULL) {
        list->head = n;
        return 0;
    } 
    struct node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    return 0;   
}

int list_insert(struct list* list, void *data, int index){
    return 0;
}





