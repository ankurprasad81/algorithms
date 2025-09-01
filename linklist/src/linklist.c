#include "linklist.h"
#include <stdlib.h>
#include <assert.h>

static node_t *preparedata(int x);
int main(int argc, char *argv[])
{
   PARAM_UNUSED(argc);
   PARAM_UNUSED(argv);

    list_t list;
    lstInit(&list);
    
    lstAddHead(&list, preparedata(5));
    lstAddHead(&list, preparedata(10));
    lstAddHead(&list, preparedata(20));
    lstAddTail(&list, preparedata(40));
    lstAddHead(&list, preparedata(30));
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
    return &data->node;
}
