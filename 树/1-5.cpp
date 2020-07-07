/*
 * 题目：二叉搜索树中的众数
 * 链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 */

#include <algorithm>
#include <vector>
#include <map>

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

void traverse(TreeNode *root, map<int, int> &hash)
{
    if (root)
    {
        traverse(root->left, hash);
        hash[root->val]++;
        traverse(root->right, hash);
    }
}

vector<int> findMode(TreeNode *root)
{
    vector<int> values, nums;
    if (!root)
        return nums;
    map<int, int> hash;
    traverse(root, hash);

    // 按照每个结点值出现的次数进行降序排序
    for (auto p : hash) values.push_back(p.second);
    sort(values.begin(), values.end(), greater<int>());

    // 寻找众数
    int max = values[0];
    for (auto p : hash)
    {
        if (p.second == max)
            nums.push_back(p.first);
    }
    return nums;
}