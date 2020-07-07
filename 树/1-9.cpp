/*
 * 题目：平衡二叉树
 * 链接：https://leetcode-cn.com/problems/balanced-binary-tree/
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int v)
    {
        this->val = v;
        left = nullptr;
        right = nullptr;
    }
};

// 计算以root为根结点的二叉树的最大深度
int depth(TreeNode *root)
{
    if (!root) return 0;

    return max(depth(root->left), depth(root->right)) + 1;
}

// 判断以root为根结点的二叉树是否平衡
bool isBalanced(TreeNode *root)
{
    if (!root) return true;

    // 左右子树高度差的绝对值
    int diff = abs(depth(root->left), depth(root->right));

    return diff <= 1 && 
           isBalanced(root->left) &&  // 左子树是否平衡
           isBalanced(root->right);   // 右子树是否平衡
}