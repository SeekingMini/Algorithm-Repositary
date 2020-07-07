/*
 * 题目：二叉搜索树中的插入操作
 * 链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
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

// 中序遍历二叉树
void traverse(TreeNode* root)
{
    if (root) {
        traverse(root->left);
        cout << root->val << " ";
        traverse(root->right);
    }
}

// 根据val的大小进行二叉树的遍历，当遍历到空结点时，就插入这个结点。
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if (!root)
        return new TreeNode(val);
    
    // val值比root值小，则递归到root左子树上寻找插入点（插入点在root左子树上）
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    // val值比root值大，则递归到root右子树上寻找插入点（插入点在root右子树上）
    if (val > root->val) root->right = insertIntoBST(root->right, val);

    return root;
}

int main()
{
    int val;
    cin >> val;

    // 手动创建二叉树
    auto root = new TreeNode(4);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(7);
    auto n3 = new TreeNode(1);
    auto n4 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    // 插入结点
    TreeNode* newroot = insertIntoBST(root, val);
    traverse(root);
    cout << endl;

    return 0;
}