#include <iostream>

using namespace std;

// 递归的方式反转(打印)链表
// 隐式的使用了栈

struct Node
{
    int data;
    struct Node* next;
};

struct Node* Append(struct Node* head,int x)
{
    Node* temp = head;
    if (temp==NULL)
    {
        head = new Node();
        head->data = x;
        head->next = NULL;
        return head;;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    temp->next = temp1;
    return head;
}

struct Node* Reverse(struct Node* head)
{
    if (head->next==NULL || head == NULL) return head;
    struct Node* new_head = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

void Print(struct Node* head)
// 使用递归的方式打印
{
    if (head==NULL) return;
    cout << head->data << ' ';
    Print(head->next);
}

void ReversedPrint(struct Node* head)
// 使用递归的方式反向打印链表
{
    if (head==NULL) return;
    ReversedPrint(head->next);      // 两个函数的区别仅在于两行代码换了个位置
    cout << head->data << ' ';
}

int main()
{
    Node* head = NULL;
    head = Append(head,1);
    head = Append(head,2);
    head = Append(head,3);
    head = Append(head,4);
    cout << "The List is :" << endl;
    Print(head);
    cout << endl << "Reversed Print is :" << endl;
    ReversedPrint(head);
    head = Reverse(head);
    cout << endl << "Reversed II :" << endl;
    Print(head);
    return 0;
}