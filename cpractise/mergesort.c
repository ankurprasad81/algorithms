/* Merging of 2 sorted arrays */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

void merge(int arr1[], uint32_t Al , int arr2[], uint32_t Bl);
int main() {
    int A[]={1,3,5,7,8,11};
    int B[]={2,6,9,10};
    uint32_t Alen=sizeof(A)/sizeof(A[0]);
    uint32_t Blen=sizeof(B)/sizeof(B[0]);
    merge(A,Alen,B,Blen);
    return 0;
}

void merge(int arr1[], uint32_t Al , int arr2[], uint32_t Bl)
{
    uint32_t i=0;
    uint32_t j=0;
    uint32_t k =0;
    int* C = (int*)calloc(Al+Bl, sizeof(int));
    assert(C!=NULL);
    /*continue loop till we reach end of any of the arrays*/ 
    while((i < Al) && (j < Bl))
    {
        if(arr1[i] > arr2[j])
            C[k++]=arr2[j++];
        if(arr1[i] < arr2[j])
            C[k++]=arr1[i++];
        else
            C[k++]=arr1[i++];

    }
    for(; i <Al; i++)
        C[k++]=arr1[i];
    for(; j < Bl; j++)
        C[k++]=arr2[j];    

    for( i = 0; i < k ; i++)
        printf("%d ", C[i]);

    if(C)
    free(C);
    C=NULL;
}