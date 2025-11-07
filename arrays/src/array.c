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
int main()
{
    
    int A[]={1,4,7,10,2,3,4,5};
    int length = sizeof(A)/sizeof(A[0]);
    rotateLeft(A,length,5);
    rotateRight(A,length, 6);
    Display(A, length);
    return 0;
}
