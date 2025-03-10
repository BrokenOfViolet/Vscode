#include <iostream>

using namespace std;
// 使用数组实现一个栈
// 栈的常见操作：push（x）， pop（）//弹出最后一个值，top（）返回栈顶的值

int top = -1; // 表示一个空栈
static int Array[10];

void Push(int x)
// 花费constant time or O（1）
{
    top = top + 1;  // 其实还需要处理元素溢出的情形,元素溢出时，需要复制原先的数组O(n)
    // best case:O(1) worst case:O(n) average case O(1)
    Array[top] = x;
}

void Pop()
{
    top = top - 1;
}

int Top()
{
    return Array[top];
}

void Print()
{
    for (int i=0; i<=top; i++)
    {
        cout << Array[i] << ' ';
    }
    cout << endl;
}
int main()
{
    Push(2); Print();
    Push(4); Print();
    Push(8); Push(0);
    Print();    // 2 4 8 0
    int Stack_top = Top();
    cout << "top of stack = " << Stack_top << endl;
    return 0;
}



/* 面向对象方法

#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // 将元素推入栈顶
    void push(int x) {
        elements.push_back(x);
    }

    // 从栈顶弹出元素
    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    // 返回栈顶元素
    int top() {
        if (!isEmpty()) {
            return elements.back();
        }
        // 如果栈为空，则返回一个特殊值（可以根据实际需求进行修改）
        return -1;
    }

    // 检查栈是否为空
    bool isEmpty() {
        return elements.empty();
    }
};

int main() {
    Stack myStack;
    
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element: " << myStack.top() << endl; // 输出 15

    myStack.pop();
    cout << "Top element after pop: " << myStack.top() << endl; // 输出 10

    return 0;
}

*/