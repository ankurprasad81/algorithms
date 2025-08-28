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
    if (( NULL!= list) && (NULL != node))
    {
    list_t *tmp = list;

    /* get current node count */
    unsigned int prevCnt = lstCount(tmp);
    
    /* if list is empty, head and tail points to same data */
    if (0 == prevCnt)
    {
        tmp->head = tmp->tail = node;
        /* update the next pointer of data to point to NULL */
        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        tmp->tail->next = node;
        node->prev = tmp->tail;
        node->next = NULL;
        tmp->tail = node;
    }
    /* increment the nodecount */
    tmp->nodecount++;
    retcode = (lstCount(tmp) == (prevCnt + 1)) ? EXIT_SUCCESS : EXIT_FAILURE;
}
    return retcode;
}