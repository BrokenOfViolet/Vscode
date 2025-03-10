#include <iostream>

using namespace std;

// 从一颗平衡二叉树中删除一个节点
// 3 cases in total
// 1. 被删除的节点没有孩子
// 2. 被删除的节点有一个孩子
// 3. 被删除的节点有两个孩子 -- 可以将case3转化为case2，具体思路为
// 找到此节点的右子树中的最小值（或者左子树中的最大值），替换掉这个节点，然后删除右（左）子树中的节点

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

struct Node* FindMin(struct Node* root)
// 寻找最小值
{
    if (root == NULL) return NULL;
    if (root->left == NULL)
        return root;
    return FindMin(root->left);
}

struct Node* Delete(struct Node* root, int x)
// 返回删除后的树
{
    if (root == NULL)
        return root;
    else if (x < root->data)
        root->left = Delete(root->left, x);
    else if (x > root->data)
        root->right = Delete(root->right, x);
    else {
        // case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;   
        }
        // case 2: just one child
        else if (root->left == NULL)
        {
            struct Node* temp = root;
            root = temp->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node* temp = root;
            root = temp->left;
            free(temp);
        }
        // case 3: two children
        else {
            struct Node* temp = FindMin(root->right);
            root->data = temp->data; // 找到右子树中的最小值
            root->right = Delete(root->right, temp->data); // 删除右子树中的that data;
        }
    }
    return root;
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
    cout << endl << "After deletion 10:";
    root = Delete(root, 10);
    cout << endl << "InOrder traversal is:";
    InOrder(root);
    cout << endl;
    return 0;
}
