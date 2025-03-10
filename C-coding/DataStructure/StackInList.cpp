#include <iostream>

using namespace std;
// Stack ADT : Last In First Out(LIFO)
// 使用链表的方式实现一个栈

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top;

void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void Pop()
// delete the element from top stack
{
    if (top == NULL) 
    {
        cerr << "Stack is Empty. " << endl;
        return;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // 这里使用temp的原因是要释放内存，删除pop掉的Node
    temp = top;
    top = top->link;
    free(temp);
}

void Print()
{
    struct Node* temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

int main()
{
    top = NULL; // 表示空栈
    Push(1); Push(3); Push(4); Print();
    Pop(); Push(1); Print();
    return 0; 
}