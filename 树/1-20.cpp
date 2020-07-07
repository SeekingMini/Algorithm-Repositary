/*
 * 题目：N叉树的前序遍历
 * 链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
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
        nums.push_back(root->val);
        for (auto node : root->children)
        {
            traverse(node, nums);
        }
    }
}

vector<int> preorder(Node *root)
{
    vector<int> nums;
    traverse(root, nums);
    
    return nums;
}