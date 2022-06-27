#ifndef GENERIC_LINKED_LIST_HEADER
#define GENERIC_LINKED_LIST_HEADER

struct node {
    void *data;
    struct node *next;
};

/* Function: list_create
 * ------
 * creates an empty linked list
 * 
 * @returns: pointer to head of empty linked list
 */

node *list_create() {
    return struct node* head = NULL;
}

#endif
