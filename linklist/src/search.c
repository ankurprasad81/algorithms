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
    int count = -2;
    if ((NULL == list) || (NULL == node))
        return count;

    count = 0;
    node_t *tmpNode = NULL;
    for (tmpNode = lstFirst(list); (NULL != tmpNode); tmpNode = lstNext(tmpNode))
    {   
        printf("lstFind:%d\n",((mydata_t*)node)->data);
        if (((mydata_t*)tmpNode)->data != ((mydata_t*)node)->data)
            ++count;
        else
            break;
    }
    return (count == (int)list->nodecount) ? -1 : count;
}

/********************************************************
@brief returns the first node in the list .
@param list: list to return from
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/
node_t *lstFirst(list_t *list)
{
    return (!lstIsEmpty(list)) ? list->head : NULL;
}

/********************************************************
@brief returns the last node in the list .
@param list: list to return from
@return NULL when list is empty
        pointer to first node if list is not empty
********************************************************/
node_t *lstLast(list_t *list)
{
    return (!lstIsEmpty(list)) ? list->tail : NULL;
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
    return ((NULL != node) && (NULL != node->prev)) ? node->prev : NULL;
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
    return ((NULL != node) && (NULL != node->next)) ? node->next : NULL;
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
    /* check if list empty */
    if (!lstIsEmpty(list))
    {
        tmpNode = lstFirst(list);
        /* if single node is available */
        if ((NULL != tmpNode) && (NULL == tmpNode->prev) && (NULL == tmpNode->next))
        {
            list->head = list->tail = NULL;
        }
        else
        {
            if (NULL != lstNext(tmpNode))
                list->head = tmpNode->next;
            tmpNode->next->prev = NULL;
            /* if the head and tail become same*/
        }
        list->nodecount--;
    }
    return tmpNode;
}