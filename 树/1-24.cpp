/*
 * 题目：二叉搜索树的范围和
 * 链接：https://leetcode-cn.com/problems/range-sum-of-bst/
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

// 中序遍历二叉树并进行累加
int rangeSumBST(TreeNode* root, int L, int R)
{
    if (!root)
        return 0;

    // root结点值小于L，去root右子树搜索
    if (root->val < L)
        return rangeSumBST(root->right, L, R);
    // root结点值大于R，去root左子树搜索
    if (root->val > R)
        return rangeSumBST(root->left, L, R);
    
    // root结点值符合要求，但是不知道root左右子树的情况，所以都要搜索
    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

int main()
{
    int L, R;
    cin >> L >> R;

    // 手动创建二叉树
    auto root = new TreeNode(10);
    auto n1 = new TreeNode(5);
    auto n2 = new TreeNode(15);
    auto n3 = new TreeNode(3);
    auto n4 = new TreeNode(7);
    auto n5 = new TreeNode(18);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    // 计算范围和
    int sum = rangeSumBST(root, L, R);
    cout << sum << endl;

    return 0;
}
