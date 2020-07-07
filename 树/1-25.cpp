/*
 * 题目：N叉树的最大深度
 * 链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
 */

#include <iostream>

using namespace std;

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

int maxDepth(Node *root)
{
    if (!root)
        return 0;
    
    vector<int> depths;
    for(Node* node: _children)
        depths.push_back()
}