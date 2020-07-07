/*
 * 题目：二叉树的镜像
 * 链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
 */

#include <iostream>

using namespace std;

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

// 遍历二叉树
void traverse(TreeNode *root) {
    if (root) {
        cout << root->val << " ";
        traverse(root->left);
        traverse(root->right);
    }
}

// 翻转二叉树
TreeNode *mirrorTree(TreeNode *root)
{
    if (!root) return nullptr;

    // 交换左右子树
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    // 在左右子树上进行翻转
    root->left = mirrorTree(root->left);  
    root->right = mirrorTree(root->right); 

    return root;
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(3);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(5);
    auto n3 = new TreeNode(1);
    auto n4 = new TreeNode(2);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;

    // 翻转二叉树
    TreeNode* newroot = mirrorTree(root);
    traverse(newroot);
    cout << endl;

    return 0;
}