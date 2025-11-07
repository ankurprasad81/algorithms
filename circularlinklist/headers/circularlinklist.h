#ifndef CIRCULARLINKLIST_H_
#define CIRCULARLINKLIST_H_

/* header file included in cpp source */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "linklist.h"




/* supported operations */

/* function to check if list is empty */
extern int clstIsEmpty(list_t* list);
/* function to initialize the list */
extern int clstInit(list_t* list);
/* function to add the node to head of the list */
extern int clstAddHead(list_t *list, node_t *node);
/* function to add the node to the end of list */
extern int clstAddTail(list_t* list, node_t* node);
/* function to insert the node after the previous node */
extern int clstInsertAfter(list_t* list, node_t* current, node_t* node);
/* function to insert the node before the previous node */
extern int clstInsertBefore(list_t* list, node_t* current, node_t* node);
/* function to return the nodes in the list */
extern int clstCount(list_t* list);
/* function to find the node in the list */
extern int clstFind(const list_t* list, const node_t* node);
/* function to return the first node from list */
extern node_t* clstFirst( list_t* list);
/* function to return the last node in the list*/
extern node_t* clstLast(list_t* list);
/* function to return the previous node */
extern node_t* clstPrevious(node_t* node);
/* function to return the next node */
extern node_t* clstNext(node_t* node);
/* function to get the first node from the list and deletes it */
extern node_t* clstGet(list_t* list);
/* function to delete the node from the list */
extern int clstDelete(list_t* list, node_t* node);
/* function to delete the complete list */
extern int clstFree(list_t* list);
/* function to display the list */
extern void clstDisplay(constlist_t* list);





#ifdef __cplusplus
}
#endif

#endif /* end of CIRCULARLINKLIST_H_*/