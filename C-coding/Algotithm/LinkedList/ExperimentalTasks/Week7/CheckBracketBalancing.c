#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    char ch;
    struct Node* link;
};

struct Node* top;       // 使用全局变量

bool isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

struct Node* Push(char ch)
{
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current->ch = ch;
    current->link = top;
    top = current;
    return top;
}

char Pop()
{
    if (isEmpty()) {
        printf("The stack is empty.\n");
        return -1;
    }
    char top_element = top->ch;
    struct Node* temp = top;
    top = temp->link;
    free(temp);
    return top_element;
}

void Print()
{
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%c ",temp->ch);
        temp = temp->link;
    }
}

int main()
{
    top = NULL; // 初始化栈,表示空栈
    char exp[20];
    char result;
    printf("请输入括号表达式:");
    scanf("%s",exp);
    for (int i=0; exp[i]!='\0'; i++) {
        ch = exp[i];
        if (ch=='(' || ch=='[' || ch=='{')
            Push(ch)
        else if (ch==')' || ch==']' || ch=='}') {
            result = Pop();
            switch(result) {
                case '(' :
            }
        }

    }
    return 0;
}