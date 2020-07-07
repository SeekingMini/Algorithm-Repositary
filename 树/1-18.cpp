/*
 * 题目：二叉搜索树中的众数
 * 链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 */

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

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

// 遍历二叉树，计算每个结点的出现次数
void traverse(TreeNode *root, map<int, int> &hash) {
    if (root) {
        traverse(root->left, hash);
        hash[root->val]++;
        traverse(root->right, hash);
    }
}

vector<int> findMode(TreeNode *root) {
    vector<int> values, nums;
    if (!root) return nums;
    map<int, int> hash;
    traverse(root, hash);

    // 将value值进行排序
    for (auto p: hash)
        values.push_back(p.second);
    sort(values.begin(), values.end(), greater<int>());

    // 寻找众数
    int max = values[0];
    for (auto p: hash) {
        if (p.second == max)
            nums.push_back(p.first);
    }
    return nums;
}

int main() {
    // 手动创建二叉树
    auto *root = new TreeNode(1);
    auto *n1 = new TreeNode(2);
    auto *n2 = new TreeNode(1);
    auto *n3 = new TreeNode(2);
    auto *n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;

    // 寻找众数
    vector<int> nums = findMode(root);
    for (int n: nums)
        cout << n << " ";
    cout << endl;

    return 0;
}