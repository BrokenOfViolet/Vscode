#include <iostream>

using namespace std;
// 实现链表的删除操作，步骤如下：
// 1.Fix the Linked list
// 2.free the space
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;

void Append(int x)
{
    Node* temp1 = head;
    if (temp1==NULL)
    {
        head = new Node();
        head->data = x;
        head->next = NULL;
        return;
    }
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    Node* temp2 = new Node();
    temp2->data = x;
    temp2->next = NULL;
    temp1->next = temp2;
}

void Delete(int index)
// the index is the position you want to delete
{
    Node* temp1 = head;
    if (index==1)
    {
        head = temp1->next;
        delete temp1;
    } else {
    for (int i=0; i<index-2; i++)
    {
        temp1 = temp1->next;
        // temp1指向(n-1)th的Node，第n个就是要删除的节点
    }
    Node* temp2 = temp1->next;  // temp2此时就相当于第n个Node
    temp1->next = temp2->next;
    delete temp2;
    }
}

void DeleteCertainValue(int value)
// 删除特定的值
{
    Node* temp1 = head;
    int index = 1;
    while (temp1!=NULL)
    {
        if (temp1->data == value) break;
        index += 1;
        temp1 = temp1->next;
    }
    if (index==1)
    {
        head = temp1->next;
        delete temp1;
    }else if (temp1==NULL){
        cout << "Can not find the value " << value << endl;
        delete temp1;
    } else {
        Delete(index);
    }
}

void Print()
// 直接复制粘贴
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
    Append(2);
    Append(1);
    Append(0);
    Append(2);
    Append(4);
    cout << "The List is:" << endl;
    Print();
    DeleteCertainValue(1);
    cout << "After Deletion:" << endl;
    Print();    
}