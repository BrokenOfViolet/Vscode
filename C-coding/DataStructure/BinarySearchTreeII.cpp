#include <iostream>

using namespace std;
// 用循环的方式实现二叉查找树的插入与搜索

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* root;

void Insert(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node* temp = root;
    while (temp != nullptr)
    {
        if (x <= temp->data)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

bool Search(int x)
{
    Node* temp = root;
    if (temp == NULL) return false;
    while (temp != NULL)
    {
        if (x < temp->data)
        {
            temp = temp->left;
        } else if (x > temp->data)
        {
            temp = temp->right;
        } else return true;
    }
    return false;
}

int main()
{
    root = NULL;
    Insert(10); Insert(9); Insert(12); Insert(6);
    int number;
    cout << "Enter the number Be Searched:" << endl;
    cin >> number;
    if (Search(number)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    return 0;
}