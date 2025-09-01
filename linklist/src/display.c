#include "linklist.h"
#include <stdlib.h>
#include "assert.h"

/********************************************************
@brief displays the content of the list .
@param list: list where to insert
@return none
********************************************************/
void lstDisplay(list_t *list)
{
    node_t *node = NULL;
    for( node = lstFirst(list); node!=NULL; node=lstNext(node))
    {
        if (node != list->tail)
        {
            printf("%d-->", ((mydata_t*)node)->data);
        }
        else
        {
            printf("%d\n", ((mydata_t*)node)->data);
        }
    }
    printf("nodecount:%d\n", list->nodecount);
    /* to check that the list is travered fully */
}