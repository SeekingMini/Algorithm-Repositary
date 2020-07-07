/*
 * 题目：路径总和 II
 * 链接：https://leetcode-cn.com/problems/path-sum-ii/
 */

#include <vector>
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

void count(TreeNode *root, int s, int sum, vector<int> &path, vector<vector<int>> &paths) {
    path.push_back(root->val);
    s += root->val;

    if (!root->left && !root->right) {  // 已经遍历到叶子结点
        if (s == sum)
            paths.push_back(path);
        else {
            path.pop_back();
            return;
        }
    } else {
        // 遍历到左子树
        if (root->left) count(root->left, s, sum, path, paths);
        // 遍历到右子树
        if (root->right) count(root->right, s, sum, path, paths);
    }
    path.pop_back();  // 在返回父结点前弹出当前结点
}

vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<int> path;  // 单条路径
    vector<vector<int>> paths;
    if (!root)
        return paths;

    count(root, 0, sum, path, paths);
    return paths;
}

int main() {
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(7);
    auto n3 = new TreeNode(4);
    auto n4 = new TreeNode(1);
    auto n5 = new TreeNode(10);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;

    // 计算所有路径
    int sum = 13;
    vector<vector<int>> paths = pathSum(root, sum);

    // 打印所有路径
    for (const vector<int> &path: paths) {
        for (int n: path)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}