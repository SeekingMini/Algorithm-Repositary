/*
 * 题目：路径总和
 * 链接：https://leetcode-cn.com/problems/path-sum/
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

bool hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return false;

    sum -= root->val;
    
    // 遇到叶子结点，说明已经形成了一条从root到子结点的完整路径
    if (!root->left && !root->right) 
        return sum == 0;

    // 从左右子树上寻找是否符合和为sum的路径
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
