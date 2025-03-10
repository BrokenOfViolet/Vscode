#include <iostream>
#include <vector>

using namespace std;
// 判断是否为二叉搜索树
// 思路：最简单的方法是利用中序遍历， 检查是否为一组由小到大的数字

vector<int> result;


void InorderTraversal(Node* root)
{
    if (root != NULL) {
        InorderTraversal(root->left);
        res.push_back(root->val);
        InorderTraversal(root->right);
    }
}