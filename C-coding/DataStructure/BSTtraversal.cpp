#include <iostream>

using namespace std;

// 实现二叉树的前序，中序，后序遍历

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* Insert(struct Node* root, int x)
{
    if (root == NULL)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (x <= root->data)
    {
        root->left = Insert(root->left, x);
    } else {
        root->right = Insert(root->right, x);
    }
    return root;
}

void PreOrder(struct Node* root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    struct Node* root = NULL; // 初始化二叉树
    root = Insert(root,12);
    root = Insert(root,10);
    root = Insert(root,8);
    root = Insert(root,5);
    root = Insert(root,20);
    root = Insert(root,15);
    root = Insert(root,9);
    root = Insert(root,6);
    cout << "PreOrder traversal is:";
    PreOrder(root);
    cout << endl << "InOrder traversal is:";
    InOrder(root);
    return 0;
}

