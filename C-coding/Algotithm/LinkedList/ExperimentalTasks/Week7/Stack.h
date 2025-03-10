#include <iostream>
#include <string>
#include <vector>   // 借助容器这个Stack很好构造

using namespace std;

template<class ElementType>
class Stack {
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
private:
    vector<ElementType> elements;
    int top;
};