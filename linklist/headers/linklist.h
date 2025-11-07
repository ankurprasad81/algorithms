#ifndef LINKLIST_H_
#define LINKLIST_H_

/* check for inclusion of linklist.h in cpp file */
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>

#define FREE(x) do {if (NULL != (x)) { (x)->next=NULL; (x)->prev = NULL; free(x) ; (x) = NULL;}}while(0);
#define PARAM_UNUSED(x) (void)(x)

typedef struct list_ list_t;
typedef struct node_ node_t;
typedef struct mydata_ mydata_t;

/* list data structure */
struct node_ {
    struct node_* next; /* next data in the list */
    struct node_* prev; /* prev data in the list */
    list_t* list; /* list containing the data */ 
};

/* list structure */
struct list_ {
    node_t* head;
    node_t* tail;
    unsigned int nodecount;
};

struct mydata_
{
    node_t node;
    int data;
};

/* supported operations */

/* function to check if list is empty */
extern int lstIsEmpty(list_t* list); /* empty function */
/* function to initialize the list */
extern int lstInit(list_t* list);
/* function to add the node to head of the list */
extern int lstAddHead(list_t *list, node_t *node);
/* function to add the node to the end of list */
extern int lstAddTail(list_t* list, node_t* node);
/* function to insert the node after the previous node */
extern int lstInsertAfter(list_t* list, node_t* current, node_t* node);
/* function to insert the node before the previous node */
extern int lstInsertBefore(list_t* list, node_t* current, node_t* node);
/* function to return the nodes in the list */
extern int lstCount(list_t* list);
/* function to find the node in the list */
extern int lstFind(list_t* list, node_t* node);
/* function to return the first node from list */
extern node_t* lstFirst( list_t* list);
/* function to return the last node in the list*/
extern node_t* lstLast(list_t* list);
/* function to return the previous node */
extern node_t* lstPrevious(node_t* node);
/* function to return the next node */
extern node_t* lstNext(node_t* node);
/* function to get the first node from the list and deletes it */
extern node_t* lstGet(list_t* list);
/* function to delete the node from the list */
extern int lstDelete(list_t* list, node_t* node);
/* function to delete the complete list */
extern int lstFree(list_t* list);
/* function to display the list */
extern void lstDisplay(list_t* list);

#ifdef __cplusplus
}
#endif

#endif /* end of fLINKLIST_H*/
