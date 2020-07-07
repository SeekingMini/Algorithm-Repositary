/*
 * 题目：找出克隆二叉树中的相同节点
 * 链接：https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 */

#include <iostream>

using namespace std;

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

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
{
    if (!original) return nullptr;
    // 找到target结点
    if (original == target) return cloned;

    // original和cloned同时按照相同方向进行深度优先遍历
    TreeNode *res;
    // 从左子树开始找
    res = getTargetCopy(original->left, cloned->left, target);
    if (res) return res;
    // 从右子树开始找
    res = getTargetCopy(original->right, cloned->right, target);
    if (res) return res;
    
    return nullptr;
}

int main()
{
    // 手动创建二叉树
    TreeNode *original = new TreeNode(1);
    TreeNode *n11 = new TreeNode(2);
    TreeNode *n12 = new TreeNode(3);
    original->left = n11;
    original->right = n12;

    TreeNode *cloned = new TreeNode(1);
    TreeNode *n21 = new TreeNode(2);
    TreeNode *n22 = new TreeNode(3);
    cloned->left = n21;
    cloned->right = n22;

    // 寻找目标结点
    TreeNode *target = n11;
    TreeNode *res = getTargetCopy(original, cloned, target);
    cout << res->val << endl;

    return 0;
}