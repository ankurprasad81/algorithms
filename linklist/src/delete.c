
#include "linklist.h"
#include <stdlib.h>
#include "assert.h"
/********************************************************
@brief deletes the node in the list .
@param list: list from where the node will be deleted.
@param node: node to search
@return EXIT_FAILURE when data is not found
        EXIT_SUCCESS when when data found
********************************************************/
int lstDelete(list_t** list, node_t* node) {

    list_t* tmp = *list;
}

/********************************************************
@brief deletes complete list .
@param list: list to be deleted.
@return EXIT_FAILURE when list is not fully deleted.
        EXIT_SUCCESS when list and its node are deleted.
********************************************************/
int lstFree(list_t** list) {

}