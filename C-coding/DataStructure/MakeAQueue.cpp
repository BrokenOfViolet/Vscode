#include <iostream>

using namespace std;

#define N 4   // 定义队列的大小为4

int queue[N];  // 初始化队列
int front = -1; // 这里的front是出队的一端
int rear = -1;  // rear是入队的一端

bool IsEmpty()
{
    if (front == -1 && rear == -1)  return true;
    else return false;
}

void Enqueue(int x)
{
    if ((rear + 1) % N == front) // 队列已满
    {
        cout << "The queue is full now" << endl;
        return;
    }
    else if (IsEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % N;
    }
    queue[rear] = x;
}

int Dequeue()
// 这个Dequeue函数返回出队的元素
{
    if (IsEmpty())
    {
        cout << "The queue is empty now" << endl;
        return -1;
    }
    int x = queue[front];
    if (front == rear) // 队列中只有一个元素
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % N;
    }
    return x;
}

void Print()
// 输出队列中的元素
{
    if (IsEmpty())
    {
        cout << "The queue is empty now" << endl;
        return;
    }
    int i = front;
    do
    {
        cout << queue[i] << " ";
        i = (i + 1) % N;
    } while (i != (rear + 1) % N);
}

int main()
{
    Enqueue(5);
    Enqueue(2);
    Enqueue(0);
    Print();
    cout << endl;
    Enqueue(1);
    Enqueue(3);
    Dequeue();
    Enqueue(8);
    Print();
    return 0;
}
