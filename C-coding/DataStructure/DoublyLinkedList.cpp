#include <iostream>

using namespace std;
// 双向链表（doubly linked list） 区别于单向链表（single linked list）

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

Node* head = NULL; // 在C++中可以这么写，在C中一般写：struct Node* head = NULL;

Node* GetNewNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    Node* newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void InsertAtTail(int x)
{
    Node* newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Print()
{
    Node* temp = head;
    cout << "Forward : ";
    if (head == NULL) return;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

void ReversePrint()
{
    Node* temp = head;
    cout << "Reverse : ";
    if (head == NULL) return;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp!=NULL)
    {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    InsertAtHead(0); Print() ; ReversePrint();
    InsertAtHead(2); Print() ; ReversePrint();
    InsertAtHead(5); Print() ; ReversePrint();
    InsertAtTail(1314); Print() ; ReversePrint();
    return 0;
}
