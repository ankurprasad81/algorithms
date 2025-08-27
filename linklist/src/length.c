#include "linklist.h"
#include <stdlib.h>
#include "assert.h"

/***********************************
@brief returns the length of the list
@param list
@return returns elements in the list
if list contains elements, else 0
************************************/ 
int lstCount(const list_t* const list)
{
    int retcode = 0;
    if (!lstIsEmpty(list))
    {
        retcode = list->nodecount;
    }
    return retcode;
}