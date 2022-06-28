#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct list {
    struct node* head;
    void (*data_compare)(void *v1, void *v2);
    void (*data_printer)(void *data);
    void (*data_free)(void *data);
};

struct node {
    void* data;
    struct node* next;
};

struct list* list_create(void (*data_compare)(void *v1, void* v2)){
    struct list *list = (struct list*)malloc(sizeof(struct list));
    list->head = NULL;
    list->data_compare = data_compare;
    return list;
}

struct node* node_create(void * data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->next = NULL;
    n->data = data;
    n->data = data;
    return n;
}


void list_print(struct list* list){
    struct node* temp = list->head;
    while(temp != NULL){
        list->data_printer(temp);
        temp = temp->next;
    }
}

int list_prepend(struct list* list, void *data){
    return 0;   
}

int list_append(struct list* list, void *data){
    return 0;   
}

int list_insert(struct list* list, void *data, int index){
    return 0;
}





