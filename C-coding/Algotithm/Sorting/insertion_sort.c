#include <stdio.h>

// 插入排序，时间复杂度为 O(N^2)
// 按由小到大的顺序排列
// 首先将第二个元素与第一个元素进行比较，如果第二个小于等于第一个，就讲第二个前移
// 然后将第三个与第二个，第一个进行比较，如果小于等于某一个，就插入到那个元素的前面
// 看起来好像第N个元素抽出来与前面的比较，然后插入到正确的位置

void InsertionSort(int A[], int N)
// A[] 是要排序的数组； N 是数组的大小
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = A[i];
        for (j = i; j > 0 && A[j - 1] > temp; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = temp;// 此时的tmep就是一次循环后最小的元素了，然后j也是最小的符合要求的下标了
    }
}

int main()
{
    int A[10] = {94, 70, 13, 21, 40, 64, 58, 85, 99, 31};
    int N = sizeof(A) / sizeof(A[0]);
    InsertionSort(A, N);
    printf("After Insertion:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}