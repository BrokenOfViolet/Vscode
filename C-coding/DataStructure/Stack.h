#ifndef Stack_H
#define Stack_H

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> elements;
public:
    void push(int data)
    {
        elements.push_back(data);
    }
    void pop()
    {
        elements.pop_back();
    }
    int top()
    {
        return elements.back();
    }
};

#endif // Stack_H