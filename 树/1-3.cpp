/*
 * 题目：二叉树的层次遍历 II
 * 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 */

#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int current_num = q.size(); // 当前队列元素个数（即二叉树当前层结点数 ）
        vector<int> one_level;
        for (; current_num > 0; current_num--) {
            TreeNode* f = q.front();
            q.pop();
            one_level.push_back(f->val);
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
        res.insert(res.begin(), one_level);
    }
    return res;
}
