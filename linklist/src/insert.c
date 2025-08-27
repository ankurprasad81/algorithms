#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief Inserts the data in the list .
@param list: list where to insert
@param data: data to insert
@param pos:  position in list.
@return EXIT_FAILURE when insertion fails fails
        EXIT_SUCCESS when insertion is successful
********************************************************/
int lstAddFirst(list_t **list, node_t *node)
{
    int retcode = EXIT_FAILURE;
    if (NULL != list)
    {
        unsigned int prevCnt = 0;
        list_t *tmp = *list;
        prevCnt = tmp->nodecount;
        /* if list is empty, head and tail points to same data */
        if (lstIsEmpty(tmp))
        {
            tmp->head = tmp->tail = node;
            /* update the next pointer of data to point to NULL */
            node->next = NULL;
        }
        else
        {
            node->next = tmp->head;
            tmp->head = node;
        }
        /* increment the nodecount */
        tmp->nodecount++;
        if (lstCount(tmp) == (prevCnt + 1))
        retcode = EXIT_SUCCESS;
    }

    return retcode;
}

/********************************************************
@brief Inserts the data in the list .
@param list: list where to insert
@param prev: Node to insert after
@param node: Node to insert.
@return EXIT_FAILURE when insertion fails fails
        EXIT_SUCCESS when insertion is successful
********************************************************/
int lstInsert(list_t** list, node_t* prev, node_t* node)
{

}


