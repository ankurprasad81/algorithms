#include <stdio.h>


void rotateLeft(int arr[], int length, int counts)
{
    int i = counts;
    
    while(i-- > 0)
    {
        int j;
        int temp= arr[0];
        for(j = 0; j < length; j++)
        arr[j] = arr[j+1];
        arr[length-1]=temp;
    }
    
}
void rotateRight(int arr[], int length, int counts)
{
    int i = counts;
    while(i-- > 0)
    {
        int j;
        int temp= arr[length-1];
        for(j = length-1; j >=0; j--)
        arr[j] = arr[j-1];
        arr[0]=temp;
    }
    
}
void Display(int A[], int size )
{
    for ( int i =0; i < size; i++)
    printf("%d ", A[i]);
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
    
    int A[]={1,4,7,10,2,13,44,5, 11, 67, 0, 9};
    int length = sizeof(A)/sizeof(A[0]);
    sort(A, length);
    //rotateLeft(A,length,5);
    //rotateRight(A,length, 6);
    
    Display(A, length);
    return 0;
}
