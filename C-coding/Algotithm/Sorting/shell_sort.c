#include <stdio.h>


void Shell_sort(int A[], int N)
{

}

int main()
{
    int A[10] = {94, 70, 13, 21, 40, 64, 58, 85, 99, 31};
    int N = sizeof(A) / sizeof(A[0]);
    Shell_sort(A, N);
    printf("After Insertion:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}