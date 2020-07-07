/*
 * 题目：分裂二叉树的最大乘积
 * 链接：https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree/
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int v)
    {
        this->val = v;
        left = nullptr;
        right = nullptr;
    }
};

// 后序遍历计算以root为根结点的子树的结点和
long int traverse(TreeNode* root, vector<long int>& sums)
{
    if (!root)
        return 0;

    long int res = root->val + traverse(root->left, sums) + traverse(root->right, sums);
    sums.push_back(res);

    return res;
}

int maxProduct(TreeNode* root)
{
    long res = -1;
    const int mod = 1e9 + 7;
    vector<long int> sums;
    traverse(root, sums);

    for (int i = 0; i < sums.size() - 1; i++) {
        res = max(res, sums[i] * (sums.back() - sums[i]));
    }

    return (int)(res % mod);
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(1);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(4);
    auto n4 = new TreeNode(5);
    auto n5 = new TreeNode(6);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;

    // 计算最大乘积
    int res = maxProduct(root);
    cout << res << endl;

    return 0;
}
