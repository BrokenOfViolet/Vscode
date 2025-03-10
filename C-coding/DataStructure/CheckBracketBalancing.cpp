#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 检查括号的匹配性（使用栈来实现）

class Stack {
private:
    vector<char> elements;
    int top;
public:
    Stack() { top = -1; } // 这是构造函数，初始化
    void push(char x) {
        elements.push_back(x);
        top = top + 1;
    }
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
            top = top - 1;
        } else {
            cerr << "A empty stack " << endl;
        }
    }
    char peek() { // 修改了函数名，避免与成员变量名冲突
        if (!elements.empty()) {
            return elements.back();
        }
        cerr << "stack is empty " << endl;
        return -1;
    }
    bool isEmpty() {
        return elements.empty();
    }
};

bool CheckBalancing(const string& str) {
    Stack S;
    for (char ch : str) {
        if (ch == '(') {
            S.push(ch);
        } else if (ch == ')') {
            if (S.isEmpty() || S.peek() != '(') {
                return false;
            }
            S.pop();
        }
    }
    return S.isEmpty();
}

int main() {
    string input = "((()))";
    if (CheckBalancing(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
