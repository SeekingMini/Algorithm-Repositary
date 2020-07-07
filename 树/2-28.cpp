/*
 * 题目：从二叉搜索树到更大和树
 * 链接：https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
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

void accumulate(TreeNode* root, int& sum)
{
    if (root) {
        accumulate(root->right, sum);
        sum += root->val;
        root->val = sum;
        accumulate(root->left, sum);
    }
}

TreeNode* bstToGst(TreeNode* root)
{
    int sum = 0;
    accumulate(root, sum);

    return root;
}

int main()
{
    // 手动创建二叉树
    TreeNode* root = new TreeNode(5);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(13);
    TreeNode* n3 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(6);
    TreeNode* n5 = new TreeNode(15);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;

    // 累加
    convertBST(root);
    traverse(root);
    cout << endl;

    return 0;
}