#ifndef GENERIC_LINKED_LIST_HEADER
#define GENERIC_LINKED_LIST_HEADER

struct list;
struct node;

/* Function: list_create
 * ------
 * creates an empty linked list
 * 
 * @returns: 
 *      struct list: pointer to head of empty linked list
 */
struct list *list_create();

/* Function: node_create
 * ------
 *  creates a new node
 *  
 *  @params: 
 *      data: data to insert into the node
 *  @returns: 
 *      struct list: pointer to the newly created node 
 */
struct node *node_create();

/* Function: list_prepend
 * ------
 *  adds a new node to the beginning of the list
 *
 *  @params: 
 *      data: data to insert
 *  @returns: 
 *      0 if insert is succesful, 1 otherwise
 *
 */
int list_prepend(struct list* list, void *data);

/* Function: list_append
 * ------
 *  adds a new node to the end of the list
 *
 *  @params: 
 *      data: data to insert
 *  @returns: 
 *      0 if insert is succesful, 1 otherwise
 */
int list_append(struct list* list, void *data);

/* Function: list_insert
 * ------
 *  adds a node to a given index in the list (0 based indexing)
 *
 *  @params:
 *      data: data to insert
 *      index: index to insert at
 *  @returns:
 *      int: 0 if insert is successful, 1 otherwise
 */
int list_insert(struct list* list, void *data, int index);

/* Function: node_print
 * ------
 *  prints the data of a given node
 *
 *  @params: node: node of data to print
 *  @returns: NULL
 */
void list_print (struct list* list);

#endif
