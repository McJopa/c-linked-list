#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
    void* data;
    struct node* next;
};

struct node* list_create(){
    struct node* head = NULL;
    return head;
}

struct node* node_create(void * data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->next = NULL;
    n->data = data;
    n->data = data;
    return n;
}

void node_print(struct node* n){
    printf(n->data);
}
