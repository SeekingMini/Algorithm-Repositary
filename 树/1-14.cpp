/*
 * 题目：路径总和 III
 * 链接：https://leetcode-cn.com/problems/path-sum-iii/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// 以root作为【开头】计算路径数
int count(TreeNode* root, int sum)
{
    if (!root) return 0;

    // 自己单独能不能作为一条路径
    int oneNodePath = (root->val == sum) ? 1 : 0;
    // 左子结点能凑几个(sum-root->val)
    int leftNum = count(root->left, sum - root->val);
    // 右子结点能凑几个(sum-root->val)
    int rightNum = count(root->right, sum - root->val);

    return oneNodePath + leftNum + rightNum;
}

int pathSum(TreeNode* root, int sum)
{
    if (!root) return 0;

    // 深度优先遍历
    int rootNum = count(root, sum); // 整个树上计算路径数
    int left = pathSum(root->left, sum); // 在左子树上计算路径数
    int right = pathSum(root->right, sum); // 在右子树上计算路径数

    return rootNum + left + right;
}

int main()
{
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

    // 计算路径总和
    int sum = 13;
    int res = pathSum(root, sum);
    cout << res << endl;

    return 0;
}