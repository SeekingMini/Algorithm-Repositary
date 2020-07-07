/*
 * 题目：左叶子之和
 * 链接：https://leetcode-cn.com/problems/sum-of-left-leaves/
 */

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->val = x;
        left = nullptr;
        right = nullptr;
    }
};

void traverse(TreeNode *root, int &sum)
{
    if (root)
    {
        // root的左子结点是叶子结点
        if (root->left && !root->left->left && !root->left->right) sum += root->left->val;
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
}

int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    traverse(root, sum);

    return sum;
}

int main()
{
    // 手动创建二叉树
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;

    // 计算左叶子之和
    int sum = sumOfLeftLeaves(root);
    cout << sum << endl;

    return 0;
}