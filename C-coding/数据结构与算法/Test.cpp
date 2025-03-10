#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree(struct Node* root,int x) {
    if (root == NULL) {
        struct Node* newNode = newNode(x);
        return newNode;
    }
    for (int i=0; i<30; i++) {
        root->left = createTree(root->left,0);
        root->right = createTree(root->right,1);
    }
}

int main()
{
    struct Node* root_0 = createTree(0);
    struct Node* root_1 = createTree(1);

    
}