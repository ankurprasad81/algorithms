#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief searches the data in the list .
@param list: list where to search
@param data: node to search
@return returns the index where noe is located

********************************************************/

int lstFind(list_t *list, node_t *node)
{
    int retcode = 0;
    if ((NULL != list) && (NULL != node))
    {
        unsigned int count = 0;
        list_t *tmp = list;
        node_t *tmpNode = NULL;
        /* loop though the list to find the node index  */
        for (tmpNode = lstFirst(tmp); tmpNode != lstLast(tmp); tmpNode = lstNext(tmp))
        {
            if (tmpNode == node)
            {
                retcode = count;
                break;
            }
            else
            {
                count++;
            }
        }
    }
    return retcode;
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
node_t *lstLast(list_t *list)
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
node_t *lstPrevious(node_t *node)
{
    node_t *tmp = NULL;

    if ((NULL != node) && (NULL != node->prev))
    {
        tmp = node->prev;
    }
    return tmp;
}

/********************************************************
@brief returns the next node of the provided node .
@param list: list to return from
@param node: next node of this node will be returned
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/
node_t *lstNext(node_t *node)
{
    node_t *tmp = NULL;

    if ((NULL != node) && (NULL != node->next))
    {
        tmp = node->next;
    }
    return tmp;
}

/********************************************************
@brief removes the first node from the list and returns
               the pointer to that node.
@param list: list to return from
@param node: next node of this node will be returned
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/

node_t *lstGet(list_t *list)
{
    node_t *tmpNode = NULL;
    if (!lstIsEmpty(list))
    {
        
        
    }
    return tmpNode;
}