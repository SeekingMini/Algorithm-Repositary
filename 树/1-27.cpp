/*
 * 题目：最长同值路径
 * 链接：https://leetcode-cn.com/problems/longest-univalue-path/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int ans = INT32_MIN;

int compute(TreeNode *root) {
    if (!root)
        return 0;

    int left = compute(root->left);
    int right = compute(root->right);

    left = (root->left && root->left->val == root->val) ? left + 1 : 0;
    right = (root->right && root->right->val == root->val) ? right + 1 : 0;

    ans = max(ans, left + right);

    return max(left, right);
}

int longestUnivaluePath(TreeNode *root) {
    if (!root)
        return 0;

    compute(root);
    return ans;
}

int main() {
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(5);
    auto n3 = new TreeNode(1);
    auto n4 = new TreeNode(1);
    auto n5 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    // 计算范围和
    int length = longestUnivaluePath(root);
    cout << length << endl;

    return 0;
}