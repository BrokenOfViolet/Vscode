#include <iostream>

using namespace std;
// 主要实现链表的「增删查改」操作

struct Node
// 创建一个链表Node
{
    int data;
    struct Node* pNext;
};

struct Node* pHead = NULL; //全局变量，能访问任何位置

void Insert_atHead(int x)
// 在链表的头部插入元素（类似于栈）
{
    Node* temp = new Node();
    temp->data = x;
    temp->pNext = pHead;
    pHead = temp;
}

void PrintLinkedList()
// 打印出列表内的全部元素
{
    Node* temp1 = pHead; // 防止pHead的地址变动
    cout << "The List is:" << " ";
    while ( temp1 != NULL ) // 注意这里不是 temp1->pNext
    {
        cout << temp1->data << ' ';
        temp1 = temp1->pNext;
    }
    cout << endl;
}

int main()
{
    cout << "How many numbers?" << endl;
    int n,x; // n是元素个数，x是每个Node中的数据
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cout << "Enter the number:" << endl;
        cin >> x;
        Insert_atHead(x);
        PrintLinkedList();
    }
    return 0;
}

/*
// 如果phead不是全局变量，可以通用如下方式取得同样的效果
int main()
{
    struct Node* pHead = NULL;  // 改动处
    cout << "How many numbers?" << endl;
    int n,x; // n是元素个数，x是每个Node中的数据
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cout << "Enter the number:" << endl;
        cin >> x;
        Insert(&pHead,x);  // 改动处/传入地址，就不需要pHead = Insert(pHead,x)了
        PrintLinkedList(pHead); // 改动
    }
    return 0;
}
void Insert(Node** PtrToHead,int x); // 声明应变为这样
*/