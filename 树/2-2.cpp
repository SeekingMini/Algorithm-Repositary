/*
 * 题目：验证二叉搜索树
 * 链接：https://leetcode-cn.com/problems/validate-binary-search-tree/
 */

#include <iostream>
·#include <vector>

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

// 中序遍历
void traverse(TreeNode* root, vector<int>& nodes)
{
    if (root) {
        traverse(root->left, nodes);
        nodes.push_back(root->val);
        traverse(root->right, nodes);
    }
}

// 解法1
// 中序遍历二叉树，将结点值存入数组中再判断数组是否升序。
bool isValidBST_method1(TreeNode* root)
{
    if (!root)
        return true;
    vector<int> nodes;
    traverse(root, nodes);

    if (nodes.size() == 1)
        return true;
    for (int i = 0; i < nodes.size() - 1; i++) {
        if (nodes[i] >= nodes[i + 1])
            return false;
    }
    return true;
}

// 解法2
// 采用中序遍历，判断当前节点是否大于中序遍历的前一个节点。
// 如果大于，说明满足BST，继续遍历；
// 否则直接返回false。
bool check(TreeNode* root, int low, int high)
{
    if (!root)
        return true;

    if (root->val <= low || root->val >= high)
        return false;
    return check(root->left, low, root->val) && check(root->right, root->val, high);
}

bool isValidBST_method2(TreeNode* root)
{
    return check(root, LONG_MIN, LONG_MAX);
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(7);
    auto n3 = new TreeNode(3);
    auto n4 = new TreeNode(6);
    auto n5 = new TreeNode(10);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;

    // 验证二叉搜索树
    bool flag = isValidBST_method2(root);
    cout << flag << endl;

    return 0;
}