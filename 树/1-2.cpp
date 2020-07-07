/*
 * 题目：对称二叉树
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

// 判断以p和q为根结点的两棵二叉树是否互为镜像（对称）
bool check(TreeNode* p, TreeNode* q)
{
    // 两者皆为空结点
    if (!p && !q) return true;
    // 只有一方为空结点
    if (!p || !q) return false;

    // 比较p和q结点值是否相等
    if (p->val == q->val) {
        // 比较p和q的子树是否互为镜像
        bool m1 = check(p->left, q->right);
        bool m2 = check(p->right, q->left);
        return m1 && m2;
    } else return false;
}


bool isSymmetric(TreeNode* root)
{
    // 判断二叉树是否对称，可以这样考虑：
    // 如果右子树是左子树的镜像，则二叉树对称；
    // 同样地，如果左子树是右子树的镜像，则二叉树对称；
    // 反之，二叉树不对称。
    return check(root, root);
}

int main() {
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(4);
    auto n3 = new TreeNode(2);
    auto n4 = new TreeNode(5);
    auto n5 = new TreeNode(5);
    auto n6 = new TreeNode(2);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    
    // 判断二叉树是否对称
    bool flag = isSymmetric(root);
    cout << flag << endl;
    
    return 0;
}