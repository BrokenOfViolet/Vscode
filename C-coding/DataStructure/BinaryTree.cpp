#include <iostream>

using namespace std;

// 树的基本概念：节点的深度：从根到节点的长度。节点的高度：从节点到叶的最长长度（不是Node的个数）
// 树的高度：即根的高度
// 二叉树(binary tree)：每个节点至多有两个child的树
// 严格二叉树：每个节点有零个或者两个节点
// complete binary tee < [log2(n)] > || perfect binary tree < log2(n+1) - 1 >
// 平衡二叉树（balanced binary tree）：左子树与右子树的高度差不超过1
// height of empty tree:-1   height of one Node tree:0

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};