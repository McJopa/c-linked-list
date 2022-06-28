#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

int main(int argc, char** argv){

    struct node *head = list_create();
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    head = node_create(ptr);
    node_print(head);
    return 0;
}

