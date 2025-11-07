#include <stdio.h>
#include <string.h>


/**
 * @brief to rotate the array data to left
 * @param string data to rotate
 * @param counts number of rotations
 */
void rotateLeft(char string[], int counts)
{
    int i = counts;
    int length= strlen(string);
    while(i-- > 0)
    {
        int j;
        int temp= string[0];
        for(j = 0; j < length; j++)
        string[j] = string[j+1];
        string[length-1]=temp;
    }
    
}
/**
 * @brief to rotate the array data to left
 * @param string data to rotate
 * @param counts number of rotations
 */
void rotateRight(char string[], int counts)
{
    int i = counts;
    int length= strlen(string);
    while(i-- > 0)
    {
        int j;
        int temp= string[length-1];
        for(j = length-1; j >=0; j--)
        string[j] = string[j-1];
        string[0]=temp;
    }
    
}
int main()
{
    
    char FullName[]="AnkurPrasad";
    rotateLeft(FullName,5);
    rotateRight(FullName, 6);
    printf("%s\n", FullName);
    return 0;
}