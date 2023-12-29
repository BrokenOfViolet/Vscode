#include <stdio.h>

int linear_search(int array[], int traget, int size);
void verify(int index);

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array)/sizeof(array[0]);
    int target = 4;
    int result = 0;

    result = linear_search(array, target, size);
    verify(result);

    return 0;

}

int linear_search(int array[], int target, int size)
{
    for (int i=0; i < size; ++i)
    {
        if (array[i] == target){
            return i;
        }
    }
    return -1;
}

void verify(int index)
{
    if (index == -1){
        printf("Target not found");
    } else {
        printf("Target found index: %d", index);
    }
}