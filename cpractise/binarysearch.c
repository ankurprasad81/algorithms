// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <stdint.h>

int FirstOccurance(int a[],int n, int value);
int main() {
 
int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
int occ=FirstOccurance(arr, size, 2);
    printf("occ:%d\n", occ);
    
}
int FirstOccurance(int a[],int n, int value)
{
    int left=0;
    int right=n-1;
    int result=-1;
    while(left < right)
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

