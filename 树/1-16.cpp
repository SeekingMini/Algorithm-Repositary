/*
 * 题目：单值二叉树
 * 链接：https://leetcode-cn.com/problems/univalued-binary-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) {
        this->val = x;
        left = nullptr;
        right = nullptr;
    }
};

// 判断单值二叉树步骤
// 1. 根结点值和左子结点、右子结点值比较
// 2. 左子结点和右子结点重复步骤1
bool isUnivalTree(TreeNode *root) {
    if (!root) return true;

    bool flag = true;
    int rootVal = root->val;

    // 比较root和root左子树的值
    if (root->left) {
        if (rootVal != root->left->val) return false;
    }
    // 比较root和root右子树的值
    if (root->right) {
        if (rootVal != root->right->val) return false;
    }

    return flag && isUnivalTree(root->left) && isUnivalTree(root->right);
}

int main() {
    // 手动创建二叉树
    auto *root = new TreeNode(1);
    auto *n1 = new TreeNode(1);
    auto *n2 = new TreeNode(1);
    auto *n3 = new TreeNode(1);
    auto *n4 = new TreeNode(0);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;

    // 判断是否为单值二叉树
    bool flag = isUnivalTree(root);
    cout << flag << endl;

    return 0;
}