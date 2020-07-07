/*
 * 题目：N叉树的后序遍历
 * 链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 */

#include <iostream>
#include <vector>

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

void traverse(Node *root, vector<int> &nums)
{
    if (root)
    {
        for (auto node : root->children)
        {
            traverse(node, nums);
        }
        nums.push_back(root->val);
    }
}

vector<int> postorder(Node *root)
{
    vector<int> nums;
    traverse(root, nums);
    return nums;
}