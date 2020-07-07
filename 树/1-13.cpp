/*
 * 题目：二叉树的直径
 * 链接：https://leetcode-cn.com/problems/diameter-of-binary-tree/
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// 直径可以理解为：左子树高度 + 右子树高度
int depth(TreeNode *root, int &res)
{
    if (!root) return 0;

    // 左子树高度
    int left = depth(root->left, res);
    // 右子树高度
    int right = depth(root->right, res);

    res = max(res, left + right + 1); // 更新结果

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = 1;
    depth(root, res);

    return res - 1;
}