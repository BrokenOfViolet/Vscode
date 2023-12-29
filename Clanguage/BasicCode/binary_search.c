#include <stdio.h>

int binary_search(int array[], int target, int size);
void verify(int index);

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array)/sizeof(array[0]);
    int target = 6;
    int result = 0;

    result = binary_search(array, target, size);
    verify(result);
}

int binary_search(int array[], int target, int size)
{
    int left=0;
    int right=size-1;
    int midpoint = 0;
    while (left <= right)
    {
        midpoint = (left+right)/2;
        if (array[midpoint] == target)
        {
            return midpoint;
        } else if (array[midpoint] <= target)
        {
            left = midpoint + 1;
        } else
        {
            right = midpoint - 1;
        }
    }
    return -1;
}

void verify(int index)
{
    if (index == -1)
    {
        printf("Target not found");
    } else
    {
        printf("Target found index: %d", index);
    }
}