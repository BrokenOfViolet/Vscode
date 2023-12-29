#include <stdio.h>

struct Book
{
    char cName[20];
    int iNumber;
    char cS[20];
} book = {"electric", 56, "134-467"};

int main()
{
    struct Book* pStruct;
    pStruct = &book;
    printf("----the bookcase's information:\n");
    printf("Kind:%s\n", (*pStruct).cName);
    printf("Number:%d\n", (*pStruct).iNumber);
    printf("Serial:%s\n", (*pStruct).cS);

    return 0;
}
