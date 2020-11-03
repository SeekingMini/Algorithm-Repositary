/* 
 * 题目：二叉搜索树中第k小的元素
 * 链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
 */


#include <iostream>

using namespace std;

// 二叉树结点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int v)
    {
        this->val = v;
        left = nullptr;
        right = nullptr;
    }
};

// 计算以root为根结点的二叉树的结点数
int countNodes(TreeNode* root) {
    if (!root) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int kthSmallest(TreeNode* root, int k) {
    // 获取左子树有多少个结点
    int count = countNodes(root->left);

    if (k <= count) return kthSmallest(root->left, k);
    else if (k == count + 1) return root->val;
    else return kthSmallest(root->right, k - count - 1);
}

int main() {
    // 手动创建二叉树
    auto root = new TreeNode(5);
    auto n1 = new TreeNode(3);
    auto n2 = new TreeNode(7);
    auto n3 = new TreeNode(2);
    auto n4 = new TreeNode(4);
    auto n5 = new TreeNode(6);
    auto n6 = new TreeNode(8);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    
    // 寻找第k小的元素
    int k = 4;
    int res = kthSmallest(root, k);
    cout << res << endl;
    
    return 0;
}
