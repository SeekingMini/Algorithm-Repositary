/*
 * 题目：二叉树的层平均值
 * 链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
 */

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int v) {
        this->val = v;
        left = nullptr;
        right = nullptr;
    }
};

vector<double> averageOfLevels(TreeNode *root) {
    vector<double> avgs;
    if (!root)
        return avgs;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        double s = 0;
        int num = q.size();  // 当前层的结点数
        for (int n = 0; n < num; n++) {
            TreeNode *front = q.front();
            s += front->val;
            q.pop();
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        avgs.push_back(s / num);
    }

    return avgs;
}