#include <stdio.h>
#include <stdlib.h>
// 实现一个单链表(无表头节点），数据类型为int
struct Node
{
    int data;
    struct Node* next;
};

struct Node* Append(struct Node* head,int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* temp = head;   // 其实这里不需要使用temp,因为函数传值传入的就是一个副本，如果head是全局变量就需要这个temp
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void Delete(struct Node **head, int x)
{
    struct Node* temp = *head;
    struct Node* prev = NULL; // 用于保存前一个节点的指针

    if (temp == NULL) {
        printf("Can not operate deletion in empty list.\n");
        return;
    }

    // 删除头节点的情况
    if (temp->data == x) {
        *head = temp->next; // 更新头指针指向新的头节点
        free(temp);         // 释放被删除的节点内存
        return;
    }

    // 遍历链表找到要删除的节点
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    // 如果找到了要删除的节点
    if (temp != NULL) {
        prev->next = temp->next; // 将前一个节点的 next 指针指向要删除节点的下一个节点
        free(temp);              // 释放要删除的节点的内存
    } else {
        printf("Can not find the element %d\n", x);
    }
}

int search(struct Node* head, int x) // 查找指定元素，如果找到，返回下标，否则返回-1
{
    int index = 0;
    while (head != NULL) {
        if (head->data == x)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

struct Node* InsertAtIndex(struct Node* head, int x, int index)
// 从任意位置插入元素
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    if (head == NULL || index == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Out of range!\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void print(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node* head = NULL;   // 初始化链表
    head = Append(head,2);
    head = Append(head,0);
    head = Append(head,1);
    head=  Append(head,8);
    print(head);
    printf("\n\n");
    Delete(&head,0);
    Delete(&head,8);
    print(head);
    printf("\n\n");
    head = InsertAtIndex(head,0,1);
    head = InsertAtIndex(head,9,3);
    print(head);
    return 0;
}