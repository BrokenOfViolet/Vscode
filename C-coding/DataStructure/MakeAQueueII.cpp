#include <iostream>

using namespace std;
// 用链表的方式实现一个队列

struct Node
{
    int data;
    struct Node* next;
};

Node* front = NULL; // 出队的一端
Node* rear = NULL;  // 进队的一端

void Enqueue(int x)
{
    Node* temp = new Node();
    // In C: struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (front==NULL && rear==NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    Node* temp = front;
    if (front == NULL) return;
    if (front == rear) {
        front = rear = NULL;
    } else {
    front = temp->next;
    }
    delete temp;
}

void Print()
// 其实这里是反向打印这个链表
{
    Node* temp = new Node();
    temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // just omit this part 哈哈
}