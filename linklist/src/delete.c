
#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief deletes the node in the list .
@param list: list from where the node will be deleted.
@param node: node to search
@return EXIT_FAILURE when data is not found
        EXIT_SUCCESS when when data found
********************************************************/
int lstDelete(list_t *list, node_t *node)
{
    int retcode = EXIT_FAILURE;
    
    if ((NULL != list) && (NULL != node) && !lstIsEmpty(list))
    {
        /* if node is the only node in list */
        if ((NULL == lstPrevious(node)) && (NULL == lstNext(node)))
        {
            list->head = list->tail = NULL;
        }
        /* head node  */
        else if (NULL == lstPrevious(node))
        {
            list->head = node->next;
            node->next->prev = NULL;
        }
        /* tail node */
        else if (NULL == lstNext(node))
        {
            list->tail = node->prev;
            node->prev->next = NULL;
        }
        printf("lsDelete:%d\n", ((mydata_t*)node)->data);
        FREE(node);
        /* decrement the node count */
        list->nodecount--;
        retcode = EXIT_SUCCESS;
    }
    return retcode;
}

/********************************************************
@brief deletes complete list .
@param list: list to be deleted.
@return EXIT_FAILURE when list is not fully deleted.
        EXIT_SUCCESS when list and its node are deleted.
********************************************************/
int lstFree(list_t *list)
{
   /* delete when list is not empty*/
    if (!lstIsEmpty(list))
    {
        node_t *tmpNode = NULL;
        while((tmpNode=lstGet(list)) != NULL)
        {
            printf("lstFree:%d\n", ((mydata_t*)tmpNode)->data);
            FREE(tmpNode);
        }
        /*once teh list is deleted , initialize pointers to their default values */
        lstInit(list);
    }
    return EXIT_SUCCESS;
}