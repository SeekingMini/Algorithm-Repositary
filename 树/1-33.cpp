/*
 * 题目：两数之和 IV - 输入 BST
 * 链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
 */

#include <iostream>
#include <map>

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

// 中序遍历
void dfs(TreeNode* root, bool &flag, map<int, int> &hash, const int &target) {
    if (root) {
        dfs(root->left, flag, hash, target);
        if (hash[target-root->val]) {
            flag = true;
            return;
        }
        hash[root->val] = true;
        dfs(root->right, flag, hash, target);
    }
} 

bool findTarget(TreeNode *root, int k) {
    map<int, int> hash;
    bool flag = false;
    dfs(root, flag, hash, k);
    
    return flag;
}

int main() {
    int k;
    cin >> k;

    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(3);
    auto n2 = new TreeNode(6);
    auto n3 = new TreeNode(2);
    auto n4 = new TreeNode(4);
    auto n5 = new TreeNode(7);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    // 计算二进制之和
    bool found = findTarget(root, k);
    cout << found << endl;

    return 0;
}