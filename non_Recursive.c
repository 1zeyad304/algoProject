#include<stdio.h>
#include<stdlib.h>
int checkArray(int *array,int size)
{
    int max=0;
    for(int x=0 ; x<size ; x++)
    {
        if (array[x] == 0) {
            max = x + 1;
        }
        for(int y = 0; y<x; y++)
        {
            if (array[x]==array[y])
            {
                if((x-y)>max)
                {
                    max=(x-y);
                }
            }
        }
    }
    return max;
}
int LongestSubarray(int * arr,int size)
{

    int length =0;
    int *array = (int *)malloc(size * sizeof(int)); //Generate array using malloc
    for(int i=0 ; i<size; i++)
    {
        if (arr[i]==0)
        {
            length = length-1;
        }
        else
        {
            length = length+1;
        }
        array[i]=length;
    }
    int result = checkArray(array,size);
    free(array);
    return result;
}
int main()
{
    int a[] = {0, 0, 1, 0, 1, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Output: %d\n", LongestSubarray(a, n)); //4
    return 0;
}
