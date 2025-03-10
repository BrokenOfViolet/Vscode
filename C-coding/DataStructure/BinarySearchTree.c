#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建一个新的二叉树节点
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入操作函数
struct TreeNode* insert(struct TreeNode* root, int data) {
    // 如果树为空，则创建一个新节点作为根节点
    if (root == NULL) {
        return createNode(data);
    }

    // 如果要插入的值小于当前节点的值，则插入到左子树
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // 如果要插入的值大于等于当前节点的值，则插入到右子树
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

// 中序遍历函数，用于验证插入操作
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // 插入操作
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);

    // 中序遍历验证插入操作
    printf("Inorder traversal after insertion: ");
    inorderTraversal(root);
    printf("\n");

    preorderTraversal(root);
    printf("\n");

    postorderTraversal(root);
    printf("\n");

    // 释放内存
    // (在实际应用中可能需要使用适当的释放内存函数来遍历并释放整个树的内存)
    free(root);

    return 0;
}
