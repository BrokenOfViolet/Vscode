#include <iostream>

using namespace std;

template<class StackType>
class Stack
{
public:
    Stack(int MaxSpaceSize = 20) : top(-1), MaxSpaceSize(MaxSpaceSize) { // 初始化 top 和 MaxSpaceSize
        element = new StackType[MaxSpaceSize];
    }
    ~Stack() { delete [] element; }
    bool Isempty() { return top == -1; }
    bool Isfull() { return top >= MaxSpaceSize - 1; }
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

struct Map
{
    int AeraIndex;
    char AeraName[20];
    int ColorIndex;
};

class StackItem
{
public:
    int AeraIndex;
    int ColorIndex;

    StackItem() : AeraIndex(0), ColorIndex(0) {}
};

void MapColor(int r[7][7], int n, Stack<StackItem>& S)
// n 是地区的个数
{
    int MaxStackSize = 20;
    Stack<StackItem> Skeep(MaxStackSize);
    StackItem x,temp;
    bool flag;

    int currentAera = 1;
    int currentColor = 1;
    x.AeraIndex = currentAera;
    x.ColorIndex = currentColor;

    S.Push(x);
    currentAera++;

    while (currentAera <=n) {
        flag = true;        // flag 为 ture 表示与栈中已染色的区域比较未发现重色    
        while (!S.Isempty() && flag) {
            S.Pop(x);
            Skeep.Push(x);
            if (x.ColorIndex == currentColor && r[currentAera][x.AeraIndex])
                flag = false;
        }
            if (flag) {
                x.AeraIndex = currentAera;
                x.ColorIndex = currentColor;
                while (!Skeep.Isempty()) {
                    Skeep.Pop(temp);
                    S.Push(temp);
                }
                S.Push(x);
                currentAera++;
                currentColor = 1;
            } else {
                currentColor++;
                while (!Skeep.Isempty()) {
                    Skeep.Pop(temp);
                    S.Push(temp);
                }
                while (currentColor > 4) {
                    S.Pop(x);
                    currentColor = x.ColorIndex + 1;
                    currentAera = x.AeraIndex;
                }
                flag = true;
            }
    }
}

int main()
{
    const int n = 7;
    Stack<StackItem> S;
    StackItem result;
    int r[7][7] = {{0,1,1,1,1,1,0},
                   {1,0,0,0,0,1,0},
                   {1,0,0,1,1,0,0},
                   {1,0,1,0,1,1,0},
                   {1,0,1,1,0,1,0},
                   {1,1,0,1,1,0,0},
                   {0,0,0,0,0,0,0}};
    MapColor(r,n,S);
    cout <<"AeraIndex\t" << "ColorIndex" <<endl;
    Stack<StackItem> Stemp = S;
    for (int i=0; i<n; i++) {
        Stemp.Pop(result);
        cout << result.AeraIndex << "\t" << result.ColorIndex <<endl;
    }
    return 0;
}