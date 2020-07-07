/* 
 * 题目：合法二叉搜索树
 * 链接：https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/
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

bool check(TreeNode* root, long low, long high)
{
    if (!root)
        return true;

    if (root->val <= low || root->val >= high) return false;
    return check(root->left, low, root->val) && check(root->right, root->val, high);
}

bool isValidBST(TreeNode* root)
{
    return check(root, LONG_MIN, LONG_MAX);
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(1);
    auto n2 = new TreeNode(4);
    auto n3 = new TreeNode(3);
    auto n4 = new TreeNode(6);
    root->left = n1;
    root->right = n2;
    n2->left = n3;
    n2->right = n4;

    // 检查是否为二叉搜索树
    bool flag = isValidBST(root);
    cout << flag << endl;

    return 0;
}