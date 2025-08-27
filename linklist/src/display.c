#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"


/********************************************************
@brief displays the content of the list .
@param list: list where to insert
@return EXIT_FAILURE when displa
        EXIT_SUCCESS when full list is displayed
********************************************************/
int lstDisplay(list_t* list) {
    
    int retcode = EXIT_FAILURE;
    list_t* tmp = list;
    unsigned int count = 0;
    node_t* node = tmp->head;
    while(NULL != node)
    {
        if(node->next != tmp->tail) {
        printf("%d-->\n",node->data);
        }
        else {
            printf("%d\n",*(int*)node->data);
        }
        node = node->next;
        count++;
    }
    printf("nodecount:%d", tmp->nodecount);
    /* to check that the list is travered fully */
    if((NULL == node) && (count == tmp->nodecount)) {
        retcode = EXIT_SUCCESS;
    }
    return retcode;
}