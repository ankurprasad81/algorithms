#include "linklist.h"
#include <stdlib.h>
#include <assert.h>

static node_t *preparedata(int x);
int main(int argc, char *argv[])
{
   PARAM_UNUSED(argc);
   PARAM_UNUSED(argv);
    node_t* temp=NULL;
    node_t* dnode  = NULL;
    node_t* dnode1  = NULL;
    list_t list;
    lstInit(&list);
    
    temp = preparedata(5);
    dnode1 = temp;
    lstAddHead(&list, temp);
    lstDisplay(&list);
    temp= preparedata(10);
    lstAddHead(&list,temp );
    lstDisplay(&list);
    temp = preparedata(20);
    lstAddHead(&list, temp);
    lstDisplay(&list);
    temp = preparedata(40);
    dnode = temp;
    lstAddTail(&list, temp);
    lstDisplay(&list);
    printf("lstInsertAfter\n");
    printf("data:%d\n", ((mydata_t*)dnode)->data);
    lstInsertAfter(&list , dnode, preparedata(50));
    lstDisplay(&list);
    printf("lstInsertBefore\n");
    lstInsertBefore(&list , dnode, preparedata(70));
    lstDisplay(&list);
    printf("lstfind:%d\n", lstFind(&list,dnode1));
    temp= preparedata(30);
    lstAddHead(&list, temp);
    lstDisplay(&list);
    lstDelete(&list , dnode);
    lstDisplay(&list);
    node_t *tmp = lstGet(&list);
    printf("lstGet:%d\n", ((mydata_t *)tmp)->data);
    lstDisplay(&list);
    tmp = lstGet(&list);
    printf("lstGet:%d\n", ((mydata_t *)tmp)->data);
    lstDisplay(&list);
    lstFree(&list);
    lstDisplay(&list);
}
static node_t *preparedata(int x)
{
    mydata_t* data = calloc(1,sizeof(struct mydata_));
    assert(data!=NULL);
    data->data = x;
    printf("push:%d\n", x);
    return &data->node;
}
