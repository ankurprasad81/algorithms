#include "linklist.h"
#include <stdlib.h>
#include "assert.h"

/***********************************
@brief checks if the list is empty
@param list list 
@return retuns 1 if list empty, else 0
************************************/ 
int lstIsEmpty(list_t* list)
{
    int retcode = 0;
    if (NULL != list){
    retcode = (list->nodecount == 0);
    }
    return retcode;
}