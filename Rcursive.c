#include<stdio.h>
#include<stdlib.h>
int solveRecursive(int *sumArray, int size, int index)
{
    if (index >= size)
    {
        return 0;
    }

    int currentMax = 0;

    if (sumArray[index] == 0)
    {
        currentMax = index + 1;
    }
    for (int j = 0; j < index; j++)
    {
        if (sumArray[index] == sumArray[j])
            {
                if ((index - j) > currentMax){
                    currentMax = index - j;}
            }
    }
    int nextMax = solveRecursive(sumArray, size, index + 1);

    return (currentMax > nextMax) ? currentMax : nextMax;
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
    int result = solveRecursive(array,size,0);
    free(array);
    return result;
}
int main()
{
    int a[] = {0,0,0,1,1,0,0,0,0,1,0,1,0};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Output: %d\n", LongestSubarray(a, n)); //4
    return 0;
}
