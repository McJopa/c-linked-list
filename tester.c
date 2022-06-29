#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

struct node* head;
int data_compare(void *v1, void *v2);
void data_printer(int *data);
void data_free(void *data);

int main(int argc, char** argv){

    struct list_t *list = list_create(&data_compare, &data_printer, &data_free);
    int *i1 = (int*)malloc(sizeof(int));
    *i1 = 10;
    int *i2 = (int*)malloc(sizeof(int));
    *i2 = 20;
    int *i3 = (int*)malloc(sizeof(int));
    *i3 = 30;
    
    list_append(list, i1);
    list_append(list, i2);
    printf("length of list: %d\n", list_length(list));
    list_append(list, i3);
    printf("length of list: %d\n", list_length(list));
    
    list_prepend(list, i3);
    printf("list insert at 0: %d\n", list_insert(list, i2, 0));
    list_insert(list, i1, 1);
    printf("list insert at list length: %d\n", list_insert(list, i1, list_length(list)));
    list_print(list);

    return 0;
}

int data_compare(void *v1, void *v2){
    int a = *(int*)v1;
    int b = *(int*)v2;

    if(a < b) return -1;
    else if (b < a) return 1;
    else return 0;
}

void data_printer(int *data){
    printf("%d", *data);
}

void data_free(void *data){
    free((int*)data);
}


