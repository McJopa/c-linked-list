#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct list_t {
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

struct list_t* list_create(int (*data_compare)(void *v1, void* v2), void (*data_printer)(void *data), void (*data_free)(void *data)){
    struct list_t *list = (struct list_t*)malloc(sizeof(struct list_t));
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

int list_length(struct list_t *list){
    struct node *temp = list->head;
    int length = 0;
    while (temp != NULL)  {
        length++;
        temp = temp->next;
    }
    return length;
}

void list_print(struct list_t* list){
    struct node* temp = list->head;
    while(temp != NULL){
        list->data_printer(temp->data);
        if (temp->next != NULL) printf("->");
        temp = temp->next;
    }
    printf("\n");
}

int list_prepend(struct list_t* list, void *data){
    struct node *n = node_create(data);
    if (list->head == NULL) {
        list->head = n;
        return 0;
    }
    n->next = list->head;
    list->head = n;
    return 0;   
}

int list_append(struct list_t* list, void *data){
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

int list_insert(struct list_t* list, void *data, int index){
    if(index == 0) {
        return list_prepend(list, data);
    }
    if(index < 0) return 1;
    struct node *n = node_create(data);
    int idx = 0;
    struct node *temp = list->head;
    struct node *prev = NULL;
    
    while(idx != index && temp != NULL) {
        prev = temp;
        temp = temp->next;
        idx++;
    }
    if(idx != index) return -1;
    prev->next = n;
    n->next = temp;
    return 0;
}

int list_find(struct list_t *list, void *data) {
    struct node *temp = list->head;
    int ndx = 0;
    while (temp != NULL) {
        if (list->data_compare(data, temp->data) == 0) {
            return ndx;
        }
        temp = temp->next;
        ndx++;
    }
    return -1;
}




