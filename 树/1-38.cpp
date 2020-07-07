/*
 * 题目：二叉树的最大深度
 * 链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int v)
    {
        this->val = v;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepth(TreeNode* root)
{
    if (!root)
        return 0;

    // 分别计算左右子树的高度
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return max(left, right) + 1;
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(6);
    auto n3 = new TreeNode(2);
    auto n4 = new TreeNode(5);
    auto n5 = new TreeNode(7);
    auto n6 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    // 计算二叉树的最大深度
    int depth = maxDepth(root);
    cout << depth << endl;

    return 0;
}
