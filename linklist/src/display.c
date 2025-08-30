#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"

/********************************************************
@brief displays the content of the list .
@param list: list where to insert
@return none
********************************************************/
void lstDisplay(list_t *list)
{

    list_t *tmp = list;
    unsigned int count = 0;
    node_t *node = list->head;
    while (NULL != node)
    {
        if (node->next != list->tail)
        {
            printf("%d-->\n", node->data);
        }
        else
        {
            printf("%d\n", *(int *)node->data);
        }
        node = node->next;
        count++;
    }
    printf("nodecount:%d", list->nodecount);
    /* to check that the list is travered fully */
}