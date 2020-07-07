/*
 * 题目：二叉树的所有路径
 * 链接：https://leetcode-cn.com/problems/binary-tree-paths/
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

void build_path(TreeNode* root, string current_path, vector<string>& paths)
{
    current_path += to_string(root->val);
    if (!root->left && !root->right) // 结点是叶子结点
    {
        paths.push_back(current_path);
        return;
    }
    if (root->left)
        build_path(root->left, current_path + "->", paths);
    if (root->right)
        build_path(root->right, current_path + "->", paths);
    current_path = current_path.substr(0, current_path.size() - 2);
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> paths;
    if (root == nullptr)
        return paths;
    // 深度优先遍历寻找路径
    string current_path;

    build_path(root, current_path, paths);

    // 将vector<vector<int>>数组转换为vector<string>数组
    return paths;
}

int main()
{
    // 手动创建二叉树
    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(6);
    TreeNode* n5 = new TreeNode(2);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;

    // 打印二叉树的所有路径
    vector<string> paths = binaryTreePaths(root);
    for (string path : paths)
        cout << path << endl;

    return 0;
}