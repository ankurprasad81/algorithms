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
int lstAddTail(list_t **list, node_t *node)
{
    int retcode = EXIT_FAILURE;
    if (NULL != list)
    {
        list_t *tmp = *list;
        /* if list is empty, head and tail points to same data */
        if (isEmpty(tmp))
        {
            tmp->head = tmp->tail = node;
            /* update the next pointer of data to point to NULL */
            node->next = NULL;
        }
        else
        {
            tmp->tail->next = node;
            tmp->tail = node;
        }
        /* increment the nodecount */
        tmp->nodecount++;
    }

    return EXIT_SUCCESS;
}