#include "circularlinklist.h"

/****************************************************
 * @brief checks if circular link list is empty
 * @param list list to check
 * @return return 0 when initialized , otherwise 1
 ****************************************************/
int clstIsEmpty(list_t *list){
    return (NULL != list) ? (list -> head == NULL && list->tail = NULL) || (list->nodecount == 0) : 0
}

/****************************************************
 * @brief Initialize the circular link list
 * @param list list to initialize
 * @return return 0 when initialized , otherwise 1
 ****************************************************/
int clstInit(list_t *list)
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

/****************************************************
 * @brief Adds node to  head of list
 * @param list: list to add to
 * @param  node: node to add to list
 * @return return 0 when added , otherwise 1
 ****************************************************/
int clstAddHead(list_t *list, node_t *node)
{

    /* check for valid inputs */
    if ((node == NULL) || (node->prev != NULL) || (node->next != NULL))
        return EXIT_FAILURE;

    /* check empty list */
    if (clstIsEmpty(list))
    {
        list->head = list->tail = node;
        /* update the next pointer of data to point to NULL */
        node->next = node;
        node->prev = node;
    }
    /* list not empty */
    else
    {
        node->next = list->head;
        node->prev = list->tail;
        list->head->next = node;
        list->head->prev = node;
        list->head = node;
    }
    list->nodecount++;
    return EXIT_SUCCESS;
}

/****************************************************
 * @brief Adds node to the end of the list
 * @param list: list to add to
 * @param  node: node to add to list
 * @return return 0 when added , otherwise 1
 ****************************************************/
int clstAddTail(list_t *list, node_t *node)
{

    /* check for valid inputs */
    if ((node == NULL) || (node->prev != NULL) || (node->next != NULL))
        return EXIT_FAILURE;

    /* check empty list */
    if (clstIsEmpty(list))
    {
        list->head = list->tail = node;
        /* update the next pointer of data to point to NULL */
        node->next = node;
        node->prev = node;
    }
    /* list not empty */
    else
    {
        node_t *tnode = list->tail;
        node->next = tnode->next;
        node->prev = tnode;
        tnode->next = node;
    }
    list->nodecount++;
    return EXIT_SUCCESS;
}

/****************************************************
 * @brief returns the node count in the list
 * @param list: list to count nodes
 * @return number of nodes in the list or 0
 ****************************************************/
int clstCount(list_t *list)
{
    return (!clstIsEmpty(list)) ? list->nodecount : 0;
}

/*****************************************************
 * @brief finds the position of the node in the list
 * @param list : list to search on 
 * @param node : node to search 
 * @return index of node or -1 
 ******************************************************/
int clstFind(const list_t* list, const node_t* node)
{
    int count = -2;
    
    /* if list empty return -1 , 
    if node is NULL return empty*/
    if((NULL == list) || clstIsEmpty(list) || (node==NULL))
    return count ;

    count =0;
    node_t* tmpNode  = NULL;
    node_t* head  = NULL;
    /* get the head node */
    tmpNode = clstFirst(list);
    do
    {
        (((mydata_t*)tmpNode)->data == ((mydata_t*)node)->data) ? break; ++count;
        
        tmpNode = clstNext(tmpNode);
        /* code */
    } while (tmpNode != head);
    
    return (count == (int)list->nodecount) ? -1 : count;
}
/****************************************************
 * @brief returns the first node from the list
 * @param list: list to find the first node from
 * @return none
 ****************************************************/
node_t *clstFirst(list_t *list)
{
    /* check if list is empty*/
    return (!clstIsEmpty(list)) ? list->head : NULL;
}

/****************************************************
 * @brief returns the last node from the list
 * @param list: list to find the first node from
 * @return none
 ****************************************************/
node_t *clstLast(list_t *list)
{
    /* check if list is empty*/
    return (!clstIsEmpty(list)) ? list->tail : NULL;
}

/****************************************************
 * @brief returns the previous node from the list
 * @param list: list to find the first node from
 * @return none
 ****************************************************/
node_t *clstPrevious(node_t *node)
{
    return (node && node->prev) ? node->prev : NULL;
}

/****************************************************
 * @brief returns the next node from the list
 * @param list: list to find the first node from
 * @return none
 ****************************************************/
node_t *clstNext(node_t *node)
{
    return (node && node->next) ? node->next : NULL;
}

/****************************************************
 * @brief removes the first node from the list and
 * returns its pointer
 * @param list 
 * @return first node pointer in the list. 
 ***************************************************/
node_t* clstGet(list_t* list)
{
    /* if list not empty */
    if(!clstIsEmpty(list))
    {
        node_t* node =NULL;
        /* if single node in list
        list->head == list->tail is the condition for single node when list is not empty */
        if (list->head == lis->tail)
        {
            node = list->head;
            list->head = list->tail  = NULL;
        }
        /* if list contains more than single node */
        else
        {
            node  = list->head->next;
            list->tail->next = node;
            node->prev = list->tail;
            list->head = node;
        }
    }
    list->nodecount--;
    return node;
}

/*****************************************************
 * @brief deletes the provided node from the list
 * @param list : list to delete node from
 * @param node : node to delete
 * @return returns 0 when successful else 1
 *****************************************************/
int clstDelete(list_t* list, node_t* node)
{

}
/*****************************************************
 * @brief deletes all the nodes from the list
 * @param list : list to delete
 * @return 0 if deleted succcessfully , 1 on failure
 *****************************************************/
int clstFree(list_t* list)
{
    (NULL == list) || (clstIsEmpty(list))
    exit EXIT_SUCCESS;

    node_t head = list->head;
    do
    {
        node_t* dnode = NULL;
        dnode = clstGet(list);
        FREE(dnode);
        /* code */
    } while (tmpNode != head);
    
    return (list->nodecount == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
}
/****************************************************
 * @brief displays the list
 * @param list: list to add
 * @return none
 ****************************************************/
void clstDisplay(const list_t *list)
{

    /* if list empty return*/
    if (!clstIsEmpty(list))
    {
        node_t *tmpNode = clstFirst(list);
        do
        {
            printf("%d-->", ((mydata_t *)tmpNode)->data);
            tmpNode = clstNext(tmpnode);
        } while (tmpNode != head);
    }
}
