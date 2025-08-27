#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief searches the data in the list .
@param list: list where to search
@param data: node to search
@return EXIT_FAILURE when data is not found
        EXIT_SUCCESS when when data found
********************************************************/

node_t *lstFind(list_t *list, node_t *data)
{
}

/********************************************************
@brief returns the first node in the list .
@param list: list to return from
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/
node_t *lstFirst(list_t *list)
{
    node_t *node = NULL;
    if (!lstIsEmpty(list))
        node = list->head;
    return node;
}

/********************************************************
@brief returns the last node in the list .
@param list: list to return from
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/
node_t* lstLast(list_t* list)
{
    node_t *node = NULL;
    if (!lstIsEmpty(list))
        node = list->tail;
    return node;
}

/********************************************************
@brief returns the previous node of the provided node .
@param list: list to return from
@param node: previous node of this node will be returned
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/
node_t* lstPrevious(list_t* list, node_t* node)
{

}

node_t* lstGet(list_t* list)
{
    
}