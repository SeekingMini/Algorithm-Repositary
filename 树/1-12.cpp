/*
 * 题目：二叉搜索树的最近公共祖先
 * 链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // 3个结点的值
    int rval = root->val;
    int pval = p->val;
    int qval = q->val;

    if (rval < pval && rval < qval) // p和q都在右子树
    {
        return lowestCommonAncestor(root->right, p, q);
    } else if (rval > pval && rval > qval) // p和q都在左子树
    {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
}

int main() {
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
    
    // 寻找公共祖先
    TreeNode* p = n3;
    TreeNode* q = n4;
    TreeNode* ancestor = lowestCommonAncestor(root, p, q);
    cout << ancestor->val << endl;
    
    return 0;
}

