#ifndef LINKLIST_H_
#define LINKLIST_H_

/* check for inclusion of linklist.h in cpp file */
#ifdef __cplusplus
extern "C" {
#endif

typedef struct list_ list_t;
typedef struct node_ node_t;


/* list data structure */
struct node_ {
    void * data; /* data to include in list */
    struct node_* next; /* next data in the list */
    struct node_* prev; /* prev data in the list */
    unsigned int datatype; /* type f data included in the list */
    list_t* list; /* list containing the data */ 
};

/* list structure */
struct list_ {
    node_t* head;
    node_t* tail;
    unsigned int nodecount;
};






/* supported operations */

/* function to check if list is empty */
extern int lstIsEmpty(list_t* list);
/* function to initialize the list */
extern int lstInit(list_t* list);
/* function to add the node to head of the list */
extern int lstAddFirst(list_t **list, node_t *node);
/* function to add the node to the end of list */
extern int lstAddTail(list_t** list, node_t* node);
/* function to insert the node after the previous node */
extern int lstInsert(list_t** list, node_t* prev, node_t* node);
/* function to return the nodes in the list */
extern int lstCount(const list_t* const list);
/* function to find the node in the list */
extern node_t* lstFind(list_t* list, node_t* data);
/* function to return the first node from list */
extern node_t* lstFirst( list_t* list);
/* function to return the last node in the list*/
extern node_t* lstLast(list_t* list);
/* function to return the previous node */
extern node_t* lstPrevious(list_t* list, node_t* node);
/* function to get the first node from the list and deletes it */
extern node_t* lstGet(list_t* list);
/* function to delete the node from the list */
extern int lstDelete(list_t** list, node_t* node);
/* function to delete the complete list */
extern int lstFree(list_t** list);
/* function to display the list */
extern int lstDisplay(list_t* list);

#ifdef __cplusplus
}
#endif

#endif /* end of fLINKLIST_H*/
