#include <stdio.h>
#include "../headers/arrayADT.h"

void intialize(arrayADT_t* arr, int numelements)
{
    if(numelements <= 0) return;

    arr->array=malloc(sizeof(int) * numelements);
    assert(arr->array!=NULL);
    arr->length = 0;
    arr->size = numelements;
    arr->getLength=NULL; 
    arr->rotateLeft=rotateLeft;
    arr->rotateRight=rotateRight;
    arr->search=NULL
    arr->display=Display;
    arr->insert=NULL;
    arr->delete=NULL;
    arr->swap=swap;
    arr->merge=NULL;

}
void rotateLeft(arrayADT_t* arr, int counts)
{
    assert(arr->array!=NULL);
    int* intA = (int*)arr->array;
    int i = counts;
    while(i-- > 0)
    {
        int j;
        int temp = intA[0];
        for(j = 0; j < arr->length; j++)
        intA[j] = intA[j+1];
        intA[arr->length-1]=temp;
    }
    
}
void rotateRight(arrayADT_t* arr, int counts)
{
    assert(arr->array!=NULL);
    int* intA = (int*)arr->array;
    int i = counts;
    while(i-- > 0)
    {
        int j;
        int temp= intA[arr->length-1];
        for(j = arr->length-1; j >=0; j--)
        intA[j] = intA[j-1];
        intA[0]=temp;
    }
    
}
void Display(arrayADT_t arr)
{
    assert(arr.array!=NULL);
    for ( int i =0; i < arr.length; i++)
    printf("%d ", arr.array[i]);
    printf("\n");
}

int swap(int* pos1 , int * pos2)
{
    int temp;
    temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}
int sort(int arr[] , int length)
{
    int i,j, temp;
    
    for(i=0; i < length; i++)
    {
        for( j=i+1; j < length ; j++)
        {
            if (arr[i] > arr[j])
            {
                swap (&arr[j], &arr[i]);
            }
        }
    }
}
int insert(int arr[] , int length , int pos)
{
       
}
int main()
{
    arayADT_t arr;
    arr.initialize(&arr);
    //rotateLeft(A,length,5);
    //rotateRight(A,length, 6);
    
    Display(A, length);
    return 0;
}
