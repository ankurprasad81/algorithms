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
int lstAddHead(list_t *list, node_t *node)
{
    int retcode = EXIT_FAILURE;
    if ((NULL != node) && (NULL != list))
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
            node->next = tmp->head;
            tmp->head = node;
            node->prev = NULL;
        }

        /* increment the nodecount */
        tmp->nodecount++;

        retcode = (lstCount(tmp) == (prevCnt + 1)) ? EXIT_SUCCESS : EXIT_FAILURE;
            
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
int lstInsertAfter(list_t *list, node_t *prev, node_t *node)
{
    int retcode = EXIT_FAILURE;

    if ((NULL !=list) && (NULL != prev) && (NULL != node))
    {
        list_t *tmp = list;

        /*get current node count */
        unsigned int prvCnt = lstCount(tmp);

        /* check if list is empty */
        if (0 == prvCnt)
        {
            /* add to head if list is empty */
            retcode = lstAddHead(tmp, node);
        }
        else if (prev == tmp->tail)
        {
            /* add to tail if prev is tail node */
            retcode = lstAddTail(list, node);
        }
        else
        {
            /* insert the node after prev node */
            node_t *tmpNode = prev->next;
            prev->next = node;
            node->prev = prev;
            node->next = tmpNode;
            tmpNode->prev = node;
            tmp->nodecount++;
            retcode = (lstCount(tmp) == prvCnt + 1) ? EXIT_SUCCESS : EXIT_FAILURE;
        }
    }
    return retcode;
}

/********************************************************
@brief Inserts the data in the list .
@param list: list where to insert
@param prev: Node to insert before
@param node: Node to insert.
@return EXIT_FAILURE when insertion fails fails
        EXIT_SUCCESS when insertion is successful
*********************************************************/
int lstInsertBefore(list_t *list, node_t *prev, node_t *node)
{
    int retcode = EXIT_FAILURE;
    if((NULL != list) && (NULL != node) && (NULL != node))
    {
        
        list_t* tmp = list;

        /* get the current node count */
        unsigned int prvCnt  = lstCount(tmp);

        if( 0 == prvCnt)
        {
            /* add to head */
            lstAddHead(tmp, node);
        }
        else
        {
            node_t* tmpNode = prev->prev;
            tmpNode->next = node;
            node->prev = tmpNode;
            node->next = prev;
            prev->prev = node;
            tmp->nodecount++;
            retcode = (lstCount(tmp) == prvCnt + 1) ? EXIT_SUCCESS : EXIT_FAILURE;
        }
    }
    return retcode;
}
