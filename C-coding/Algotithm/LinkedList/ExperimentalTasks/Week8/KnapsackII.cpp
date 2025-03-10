#include <iostream>

using namespace std;

// 定义 Products 类
class Products
{
public:
    char number[10];    // 货物编号
    char name[10];      // 货物名称
    char place[20];     // 存放位置
    int weight;         // 货物体积（就这一个有用）
};

// 修改 StackType 类名为 StackItem
class StackItem
{
public:
    int index;  // 货物编号
};

// 修改 Stack 类，增加成员变量初始化
template<class StackType>
class Stack
{
public:
    Stack(int MaxSpaceSize = 20) : top(-1), MaxSpaceSize(MaxSpaceSize) { // 初始化 top 和 MaxSpaceSize
        element = new StackType[MaxSpaceSize];
    }
    ~Stack() { delete [] element; }
    bool Isempty() { return top == -1; }
    bool Isfull() { return top >= MaxSpaceSize - 1; } // 修改 Isfull 函数
    bool Push(StackType& newvalue) {
        if (Isfull())
            return false;
        element[++top] = newvalue;
        return true;
    }
    bool Pop(StackType& result) {
        if (Isempty())
            return false;
        result = element[top--];
        return true;
    }
    int GetTopAddress() {
        return top;
    }
private:
    int top;
    int MaxSpaceSize;
    StackType *element;
};

void TraverseStack(Stack<StackItem>& S, Products element[]) { // 修改参数类型为 Products
    int k;
    int topkeep;
    StackItem temp;
    int MaxStackSize = 50;
    Stack<StackItem> Skeep(MaxStackSize);
    cout << "-------- 运送方案货物信息 --------"<<endl;
    cout << "货物编号\t" << "货物名称\t" << "存放位置\t" << "货物体积\t" << endl;
    topkeep = S.GetTopAddress();
    while (!S.Isempty()) {
        S.Pop(temp);
        k = temp.index;
        cout << element[k].number << "\t";
        cout << element[k].name << "\t";
        cout << element[k].place << "\t";
        cout << element[k].weight << endl;
        Skeep.Push(temp);
    }
    cout << "该方案有以上" << topkeep+1 << "件货物"<<endl;
    while (!Skeep.Isempty()) {
        Skeep.Pop(temp);
        S.Push(temp);
    }
}

void Knapsack(Products element[], int n, int TotalVolume) { // 修改参数类型为 Products
    int MaxStackSize = 50;
    StackItem temp;
    Stack<StackItem> S(MaxStackSize);
    int k = 0;
    do {
        while (TotalVolume > 0 && k < n) {
            if (TotalVolume - element[k].weight >= 0) {
                temp.index = k;
                S.Push(temp);
                TotalVolume = TotalVolume - element[k].weight;
            }
            k++;
        }
        if (TotalVolume == 0)
            TraverseStack(S, element);
        S.Pop(temp);
        k = temp.index;
        TotalVolume = TotalVolume + element[k].weight;
        k++;
    } while (!S.Isempty() || k != n);
}

int main() {
    int TotalVolume = 100;
    const int n = 6;
    Products elements[n] = {
        {"10000", "AAAA", "www0", 20},
        {"10001", "BBBB", "www1", 30},
        {"10002", "CCCC", "www2", 40},
        {"10003", "DDDD", "www3", 50},
        {"10004", "EEEE", "www4", 80},
        {"10005", "FFFF", "www5", 10}
    };
    Knapsack(elements, n, TotalVolume);
    return 0;
}
