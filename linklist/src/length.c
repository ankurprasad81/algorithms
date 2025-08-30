#include "linklist.h"
#include <stdlib.h>
#include "assert.h"

/***********************************
@brief returns the length of the list
@param list
@return returns elements in the list
if list contains elements, else 0
************************************/ 
int lstCount(list_t* list)
{
    return (!lstIsEmpty(list)) ? list->nodecount: 0 ;
}