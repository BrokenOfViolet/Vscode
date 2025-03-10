#include <iostream>
#include <cstring>
// 用数组的方式实现链表，主要操作包含顺序表的「增删查改」
#define Student ElementType
class Student
{
public:
    char number[10];
    char name[8];
    char sex[3];
    int age;
    char place[20];
};

template<class ElementType>
class LinearList
{
public:
    LinearList(int MaxListSize=10) : length(0), MaxSpaceSize(MaxListSize) {
        element = new ElementType[MaxSpaceSize];
    }
    ~LinearList() { delete [] element; }
    int LengthLinearList() { return length; }
    bool GetElementLinearList(int k, ElementType &result)
    { // 查找第k个元素，存入result中,这个k从0开始,规定 k==index
        if (k<0 || k>length)
            return false;
        result = element[k];
        return true;
    }
    int SearchElementLinearList(char searchkey[])
    { // 查找值为searchkey的元素，找到了返回下标，未找到返回-1
        for (int i=0; i<length; i++) {
            if (!strcmp(element[i].name,searchkey)) // 这里我记得C++可以直接用==比较字符串, 还可以用strcmp(引入<cstring>)
                return i;
        } return -1;
    }
    int SearchElementLinearList(int searchkey) // 重载函数，searchkey为int类型时
    { // 查找值为searchkey的元素，找到了返回下标，未找到返回-1
        for (int i=0; i<length; i++) {
            if (element[i].key == searchkey)
                return i;
        } return -1;
    }
    bool InsertElementLinearList(int k, ElementType &newvalue)
    {   // 这个k是从0开始的,k与下标的关系：k==index
        if (k<0 || k>length)
            return false;
        if (length == MaxSpaceSize)
            return false;
        for (int i=length-1;i>=k; i--)  // 插入点的数据后移
            element[i+1] = element[i];
        element[k] = newvalue;
        length++;
        return true;
    }
    bool DeleteElementLinearList(int k)
    {   
        if (k<0 || k>length)
            return false;
        for (int i=k+1; i<length; i++) {
            element[i-1] = element[i];
        } length--;
        return true;
    }
    void DisplayElementLinearList(ElementType result);
    void DisplayLinearList(LinearList<ElementType> &AppList);
private:
    ElementType *element;
    int length; // 这个length从1开始，为0表示空
    int MaxSpaceSize;
};