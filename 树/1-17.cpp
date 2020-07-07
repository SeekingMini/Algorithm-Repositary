/*
 * 题目：二叉树中第二小的节点
 * 链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
 */

#include <iostream>
#include <set>

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

// 遍历二叉树
void traverse(TreeNode *root, set<int> &nums) {
    if (root) {
        nums.insert(root->val);
        traverse(root->left, nums);
        traverse(root->right, nums);
    }
}

int findSecondMinimumValue(TreeNode *root) {
    set<int> nums;
    traverse(root, nums);

    if (nums.size() == 1)
        return -1;
    auto p = nums.begin();
    p++;
    return *p;
}

int main() {
    // 手动创建二叉树
    auto root = new TreeNode(3);
    auto n11 = new TreeNode(4);
    auto n12 = new TreeNode(5);
    auto n13 = new TreeNode(1);
    auto n14 = new TreeNode(2);
    root->left = n11;
    root->right = n12;
    n11->left = n13;
    n11->right = n14;

    // 寻找第2小的值
    int val = findSecondMinimumValue(root);
    cout << val << endl;

    return 0;
}
