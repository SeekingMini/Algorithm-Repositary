/* 
 * 题目：二叉树的坡度
 * 链接：https://leetcode-cn.com/problems/binary-tree-tilt/
 */

#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// 计算某一个结点的坡度
int compute(TreeNode *root, int &sum)
{
    if (!root) return 0;

    // 计算左右子结点的坡度
    int left = compute(root->left, sum);
    int right = compute(root->right, sum);
    // 更新状态
    sum += abs(left - right);  
    
    return root->val + left + right;
}

int findTilt(TreeNode *root)
{
    int sum = 0;
    compute(root, sum);

    return sum;
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(1);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(4);
    auto n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    // 计算二叉树的坡度
    int sum = findTilt(root);
    cout << sum << endl;

    return 0;
}