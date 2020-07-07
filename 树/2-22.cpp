/*
 * 题目：N叉树的层序遍历
 * 链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
 */

#include <iostream>
#include <queue>
#include <vector>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> nums;
    if (!root)
        return nums;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> one;
        int size = q.size(); // 当前层的层数

        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            one.push_back(front->val);
            q.pop();
            for (auto child : front->children) {
                if (child)
                    q.push(child);
            }
        }
        nums.push_back(one);
    }

    return nums;
}