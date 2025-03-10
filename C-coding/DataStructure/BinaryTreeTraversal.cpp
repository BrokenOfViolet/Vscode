#include <iostream>

using namespace std;

// 树的遍历 ： 1. 广度优先(breadth-first)   level order
//           2. 深度优先(depth-first)
// depth-fisrt kinds: 1. <root><left><right>    preorder前序遍历
//                    2. <left><root><right>    inorder中序遍历
//                    3. <left><right><root>    postorder后序遍历

// This code 用于实现二叉树的层序遍历（level-order traversal）

template<typename T>
class Queue
{
private:
    struct TreeNode
    {
        T data;
        TreeNode* next;
    };
    TreeNode* front = NULL;
    TreeNode* rear = NULL;
public:
    void Enqueue(T x)
    {
        TreeNode* temp = new TreeNode();
        temp->data = x;
        temp->next = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    T Dequeue()
    {
        if (front == NULL)
        {
            cout << "队列为空" << endl;
            return T(); // 返回默认值
        }
        if (front == rear)
        {
            TreeNode* temp = front;
            T x = temp->data;
            front = rear = NULL;
            delete temp;
            return x;
        }
        else
        {
            TreeNode* temp = front;
            T x = temp->data;
            front = front->next;
            delete temp;
            return x;
        }
    }
    bool IsEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
};

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* root = nullptr;

Node* GetNewNode(int x)
{
    Node* BstNode = new Node();
    BstNode->data = x;
    BstNode->left = BstNode->right = nullptr;
    return BstNode;
}

Node* Insert(Node* root, int x)
{
    if (root == nullptr)
    {
        root = GetNewNode(x);
    }
    else if (root->data >= x)
    {
        root->left = Insert(root->left, x);
    }
    else
    {
        root->right = Insert(root->right, x);
    }
    return root;
}

void LevelOrder(Node* root)
{
    if (root == nullptr) return;
    Queue<Node*> Q;
    Q.Enqueue(root);
    while (!Q.IsEmpty())
    {
        Node* current = Q.Dequeue();
        cout << current->data << " ";
        if (current->left != nullptr)
            Q.Enqueue(current->left);
        if (current->right != nullptr)
            Q.Enqueue(current->right);
    }
}

int main()
{
    root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 2);
    root = Insert(root, 0);
    root = Insert(root, 13);
    root = Insert(root, 14);
    root = Insert(root, 8);
    root = Insert(root, 3);
    LevelOrder(root);
    return 0;
}