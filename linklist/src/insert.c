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

    /* check for valid inputs */
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
        /* list not empty */
        else
        {
            node->next = list->head;
            node->prev = NULL;
            list->head->prev = node;
            list->head = node;
        }

        /* increment the nodecount */
        list->nodecount++;
        retcode = EXIT_SUCCESS;
    }

    return retcode;
}

/********************************************************
@brief Inserts the data in the list .
@param list: list where to insert
@param current: Node to insert after
@param node: Node to insert.
@return EXIT_FAILURE when insertion fails fails
        EXIT_SUCCESS when insertion is successful
********************************************************/
int lstInsertAfter(list_t *list, node_t *current, node_t *node)
{
    /* ensure input is valid */
    if ((NULL == list) || (NULL == current) || (NULL == node))
        return EXIT_FAILURE;

    /* ensure node is not linked anywhere */
    if (node->next != NULL || node->prev != NULL)
        return EXIT_FAILURE;

    /* check of empty list is not required as the current is not NULL */
    if (current == list->tail)
    {
        current->next = node;
        node->prev = current;
        node->next = NULL;
        list->tail = node;
    }
    else if (current == list->head)
    {
        current->next = node;
        node->prev = current;
        node->next= NULL;

    }
    else
    {
        /* insert the node after current node */
        node_t *tmpNode = current->next;
        current->next = node;
        node->prev = current;
        node->next = tmpNode;
        tmpNode->prev = node; // TODO: null pointer dereference when signle node is available in list
    }
    list->nodecount++;
    return EXIT_SUCCESS;
}

/********************************************************
@brief Inserts the data in the list .
@param list: list where to insert
@param current: Node to insert before
@param node: Node to insert.
@return EXIT_FAILURE when insertion fails fails
        EXIT_SUCCESS when insertion is successful
*********************************************************/
int lstInsertBefore(list_t *list, node_t *current, node_t *node)
{
    /* ensure input is valid */
    if ((NULL == list) || (NULL == current) || (NULL == node))
        return EXIT_FAILURE;

    /* ensure node is not linked anywhere */
    if (node->next != NULL || node->prev != NULL)
        return EXIT_FAILURE;

}
