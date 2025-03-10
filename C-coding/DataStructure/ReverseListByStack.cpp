#include <iostream>
#include <stack>

using namespace std;
// 使用栈来翻转一个链表

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head = NULL;

void Reverse()
{
    if (head == NULL) return;
    stack<struct Node*> S;
    Node* temp = head;
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->link;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->link = S.top());
        S.pop();
        temp = temp->link;
    }
}

// 此处省略一万行代码

int main()
{
    Reverse();
    return 0;
}