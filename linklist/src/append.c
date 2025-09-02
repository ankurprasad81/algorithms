#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief Appends the data in the list .
@param list: list where to insert
@param data: data to insert
@param pos:  position in list.
@return EXIT_FAILURE when insertion fails fails
        EXIT_SUCCESS when insertion is successful
********************************************************/
int lstAddTail(list_t *list, node_t *node)
{
    int retcode = EXIT_FAILURE;
    if ((NULL != list) && (NULL != node))
    {
        /* if list is empty, head and tail points to same data */
        if (lstIsEmpty(list))
        {
            list->head = list->tail = node;
            /* update the next pointer of data to point to NULL */
            node->next = NULL;
            node->prev = NULL;
        }
        else
        {
            list->tail->next = node;
            node->prev = list->tail;
            node->next = NULL;
            list->tail = node;
        }
        /* increment the nodecount */
        list->nodecount++;
        /* keep a track of the node added to the list */
        node->list = list;
        retcode = EXIT_SUCCESS;
    }
    return retcode;
}