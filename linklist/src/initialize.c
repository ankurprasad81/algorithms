#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief Initializes the list members for the first usage.
@param list 
@return EXIT_FAILURE when initialization fails
        EXIT_SUCCESS when initialization completes
********************************************************/
int lstInit(list_t* list)
{
    int retcode = EXIT_FAILURE;
    if (NULL != list)
    { 
        list->head = NULL;
        list->tail = NULL;
        list->nodecount = 0;
        retcode = EXIT_SUCCESS;
    }
   return retcode; 
}