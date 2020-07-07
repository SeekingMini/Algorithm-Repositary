/*
 * 题目：相同的树
 * 链接：https://leetcode-cn.com/problems/symmetric-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

// 判断以p和q为根结点的两棵树是否为相同
bool isSameTree(TreeNode* p, TreeNode* q)
{
    // 只有一方为空结点
    if ((!p && q) || (p && !q)) return false;
    // 两者皆为空结点
    if (!p && !q) return true;

    // 两个结点值相同
    if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // 判断左右子树是否相同
    else return false;
}

int main() {
    // 手动创建二叉树
    auto root1 = new TreeNode(5);
    auto n11 = new TreeNode(4);
    auto n12 = new TreeNode(6);
    auto n13 = new TreeNode(2);
    root1->left = n11;
    root1->right = n12;
    n11->left = n13;
        
    auto root2 = new TreeNode(5);
    auto n21 = new TreeNode(4);
    auto n22 = new TreeNode(6);
    root2->left = n21;
    root2->right = n22;
    
    // 判断两棵树是否相同
    bool isSame = isSameTree(root1, root2);
    cout << isSame << endl;
    
    return 0;
}
