#include <iostream>

using namespace std;
// Find Min and Max in a binary tree
// Find height of a binary tree

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int x)
{
    Node* BstNode = new Node();
    BstNode->data = x;
    BstNode->left = BstNode->right = NULL;
    return BstNode;
}

Node* Insert(Node* root, int x)
{
    if (root == NULL)
    {
        root = GetNewNode(x);
        return root;
    } else if (root->data >= x)
    {
        root->left = Insert(root->left,x);
    } else {
        root->right = Insert(root->right,x);
    }
    return root;
}

int FindMin(Node* root)
// 使用递归的方式
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    } else if (root->left == NULL)
    {
        return root->data;
    }
    return FindMin(root->left);
}

int FindMax(Node* root)
// 使用迭代的方式
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int max(int a,int b)
{
    if (a>=b) return a;
    else return b;
}

int FindHeight(Node* root)
{
    if (root == NULL)
        return -1;
    return max(FindHeight(root->left),FindHeight(root->right)) + 1;
}

int main()
{
    Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,20);
    root = Insert(root,12);
    root = Insert(root,3);
    root = Insert(root,25);
    root = Insert(root,9);
    root = Insert(root,10);
    cout << "The Min:" << FindMin(root) << endl;
    cout << "The Max:" << FindMax(root) << endl;
    cout << "The Height of Tree:" << FindHeight(root) << endl;
    return 0;
}