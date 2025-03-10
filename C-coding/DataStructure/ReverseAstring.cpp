#include <iostream>
#include <stack>    // stack from standard template library ( STL )

using namespace std;
// 使用数组的方法翻转字符串 ？

void Reverse(char *C, int n)
{
    stack<char> S;
    for (int i=0; i<n; i++)
    {
        S.push(C[i]);
    }
    for (int i=0; i<n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];
    cout << "Enter a string:";
    cin.getline(C,51);
    Reverse(C,strlen(C));
    cout << "Output:" << C;
    return 0;
}