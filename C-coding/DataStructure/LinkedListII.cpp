#include <iostream>

using namespace std;
// 实现链表的插入操作（在任意位置插入）
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;
// 如果head不是全局的，可以通过返回head后者引用传递来实现相同的效果
void Insert(int data, int index)
// data是数据，index是插入的位置，本程序的索引从1开始
// 画个图比较好理解
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (index==1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    temp2 = head;
    for (int i=0; i<index-2 && temp2!=NULL; i++)
    // 循环n-1次,temp2!=NULL防止越界
    {
        temp2 = temp2->next;
    }
    if (temp2==NULL)
    {
        cout << index << " is a Invalid index" << endl;
        return;// 对于无效索引，我不打算插入，其实也可以插入到最后，注释掉return即可
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Insert(2,1);    // List : 2
    Insert(3,2);    // List : 2 3
    Insert(4,1);    // List : 4 2 3
    Insert(5,2);    // List : 4 5 2 3
    Insert(6,10);
    cout << "The List is:" << endl;
    Print();
    return 0;
}