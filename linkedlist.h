#ifndef GENERIC_LINKED_LIST_HEADER
#define GENERIC_LINKED_LIST_HEADER

struct node; 

/* Function: list_create
 * ------
 * creates an empty linked list
 * 
 * @returns: pointer to head of empty linked list
 */
struct node *list_create();

/* Function: node_create
 * ------
 *  creates a new node
 *  
 *  @params: data: data to insert into the node
 *  @returns: pointer to the newly created node 
 */
struct node *node_create();

/* Function: node_print
 * ------
 *  prints the data of a given node
 *
 *  @params: node: node of data to print
 *  @returns: NULL
 */
void node_print(struct node* n);

#endif
