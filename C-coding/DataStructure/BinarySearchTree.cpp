#include <iostream>

using namespace std;
// 二叉搜索树（BST）：每个节点左子树的所有Node的值小于此Node，右子树的大于
// 删除，插入，查找的time complexity都为O(logN)
// 用递归的方式实现二叉搜索树的插入以及查找操作


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

bool Search(Node* root,int x)
{
    if (root == NULL) return false;
    if (root->data == x) return true;
    else if (root->data >= x) Search(root->left,x);
    else Search(root->right,x);
}

int main()
{
    Node* root = NULL;
    root = Insert(root,25);
    root = Insert(root,18);
    root = Insert(root,32);
    root = Insert(root,6);
    int number;
    cout << "Enter the Number be Search:" << endl;
    cin >> number;
    if (Search(root,number)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    return 0;
}

