/*
 * 题目：二叉树中的最大路径和
 * 链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int res = INT32_MIN; // 最终需要返回的结果

// 计算以root为根结点的二叉树的和最大的路径
// 路径：root结点到二叉树中某一个结点的所有结点值的和（必须自顶向下）
int maxSum(TreeNode* root)
{
    if (!root) return 0;

    // 左子树的最大路径和，如果为负数就置0
    int left = max(0, maxSum(root->left));
    // 右子树的最大路径和，如果为负数就置0
    int right = max(0, maxSum(root->right));

    // left->root->right作为路径与历史最大值进行比较（更新状态量res）
    res = max(res, root->val + left + right);
    // 返回经过root的单边最大分支给上游
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root)
{
    maxSum(root);
    return res;
}

int main()
{
    // 手动创建二叉树
    auto* root = new TreeNode(-10);
    auto* t1 = new TreeNode(9);
    auto* t2 = new TreeNode(20);
    auto* t3 = new TreeNode(15);
    auto* t4 = new TreeNode(7);
    root->left = t1;
    root->right = t2;
    t2->left = t3;
    t2->right = t4;

    // 计算最大路径和
    int sum = maxPathSum(root);
    cout << sum << endl;

    return 0;
}
