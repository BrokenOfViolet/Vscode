#include <stdio.h>

struct Student
{
    char cName[20];
    int iNumber;
    struct Student* pNext;
};

int iCount;

struct Student* Create()
{
    struct Student* pHead=NULL;
    struct Student* pEnd, *pNew;
    iCount=0;
    pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));
    
}
