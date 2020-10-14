/*
 * 题目：寻找重复的子树
 * 链接：https://leetcode-cn.com/problems/find-duplicate-subtrees/
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

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

// 序列化以root为根的二叉树
string traverse(TreeNode* root, map<string, int>& m, vector<TreeNode*>& nodes)
{
    if (!root) return "#";

    // 后序遍历将左右子树序列化成字符串
    string left = traverse(root->left, m, nodes);
    string right = traverse(root->right, m, nodes);

    // 左右子树加上自己就是以自己为根的二叉树序列化结果
    string res = left + "," + right + "," + to_string(root->val);

    // 多次重复也只会被加入结果集一次
    int freq = m[res];
    if (freq == 1) 
        nodes.push_back(root);
    // 给子树对应的出现次数加一
    m[res] += 1;

    return res;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
    vector<TreeNode*> res;
    map<string, int> m; // 记录每个子树出现的次数

    traverse(root, m, res);
    return res;
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(1);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(4);
    auto n4 = new TreeNode(2);
    auto n5 = new TreeNode(4);
    auto n6 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    n4->left = n6;

    // 寻找重复的子树
    vector<TreeNode*> nodes = findDuplicateSubtrees(root);
    for (TreeNode* node : nodes)
        cout << node->val << " ";
    cout << endl;

    return 0;
}
