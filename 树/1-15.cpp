/*
 * 题目：另一个树的子树
 * 链接：https://leetcode-cn.com/problems/subtree-of-another-tree/
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

// 判断二叉树是否相同
bool isSameTree(TreeNode *s, TreeNode *t)
{
    if (!s && !t)
        return true;
    if (!s || !t)
        return false;

    return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

// 所有的子树是指s中的某一部分是否和t相同
bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (!s && !t) // 两者皆为空结点
        return true;
    if (!s || !t) // 只有一方为空
        return false;

    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main()
{
    // 手动创建二叉树
    auto root1 = new TreeNode(3);
    auto n11 = new TreeNode(4);
    auto n12 = new TreeNode(5);
    auto n13 = new TreeNode(1);
    auto n14 = new TreeNode(2);
    root1->left = n11;
    root1->right = n12;
    n11->left = n13;
    n11->right = n14;

    auto root2 = new TreeNode(4);
    auto n21 = new TreeNode(1);
    auto n22 = new TreeNode(2);
    root2->left = n21;
    root2->left = n22;

    // 判断root2是否为root1的子树
    cout << isSubtree(root1, root2) << endl;

    return 0;
}
