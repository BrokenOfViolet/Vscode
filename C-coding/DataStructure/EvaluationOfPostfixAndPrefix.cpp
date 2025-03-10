#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;
// 使用栈来实现后缀表达式和前缀表达式的求和
// 假设用户输入的表达式正确

Stack operandStack;

int EvaluatePostfix(const string& expression)
{
    for (char c : expression)
    {
        if (isdigit(c))
        {
            operandStack.push(c-'0');
        } else if (c == ' ')
        {
            continue;
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            switch (c) {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            // 根据需要添加更多操作符的情况
            }
        }
    }
    return operandStack.top();
}

int main()
{
    string postfixExpression = "8 3 4 * +";
    cout << "Result:" << EvaluatePostfix(postfixExpression) << endl;
    return 0;
}