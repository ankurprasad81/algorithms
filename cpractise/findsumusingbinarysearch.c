// Online C compiler (editor)
// Write and run C online using this editor.
/*
problem statement : find pairs of digits whose sum adds up to 9
*/
#include <stdio.h>
#include <stdint.h>

static int FirstOccurance(int a[],int left,int right, int value);
int main() {
 int sum = 9;
int arr[] = {2,3,6,7,11,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int indx= 0;
    for( indx=0; indx < size; indx++)
    {
        int find = sum - arr[indx];
        if( find > 0 )
        {
            int occ=FirstOccurance(arr, 0, size, find);
            printf("[%d:%d]\n", arr[indx],arr[occ]);
        }
    }
}
static int FirstOccurance(int a[],int left, int right , int value)
{
    int result=-1;
    while(left <= right)
        {
            int mid= left + ( right - left ) / 2;        
            if(a[mid] >= value)
            {
                right = mid -1 ;
                result=mid;
            }
            else
                left = mid + 1;
            
        }
    return result;
}

