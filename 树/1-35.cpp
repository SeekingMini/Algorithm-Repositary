/*
 * 题目：BiNode
 * 链接：https://leetcode-cn.com/problems/binode-lcci/
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

// 遍历被展开为链表的二叉树
// 只需要遍历右子结点即可
void traverse(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        traverse(root->right);
    }
}

// 得到root的最右边叶子结点
TreeNode *getRightLeaf(TreeNode *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

TreeNode *convertBiNode(TreeNode *root)
{
    if (!root)
        return nullptr;
    else {
        if (left) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = nullptr;
            TreeNode* rightLeaf = getRightLeaf(left);
            left->right = root;
            return convertBiNode(left);
        } else 
            return convertBiNode(root->right);
    }
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(1);
    auto t1 = new TreeNode(2);
    auto t2 = new TreeNode(3);
    auto t3 = new TreeNode(6);
    auto t4 = new TreeNode(4);
    auto t5 = new TreeNode(5);
    root->left = t1;
    root->right = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;

    // 将二叉树展开为链表
    flatten(root);
    traverse(root);
    cout << endl;

    return 0;
}