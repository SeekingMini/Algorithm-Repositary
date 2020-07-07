/*
 * 题目：二叉树的最小深度
 * 链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
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

int minDepth(TreeNode* root)
{
    if (!root) return 0;

    // 左右子树都存在
    if (root->left && root->right)
        return min(minDepth(root->left), minDepth(root->right)) + 1;

    // 右子树不存在
    if (root->left)
        return minDepth(root->left) + 1;
    else // 左子树不存在
        return minDepth(root->right) + 1;
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(6);
    auto n3 = new TreeNode(7);
    auto n4 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    // 计算二叉树的最大深度
    int depth = minDepth(root);
    cout << depth << endl;

    return 0;
}
