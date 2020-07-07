/*
 * 题目：二叉树的最近公共祖先
 * 链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	explicit TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root)
		return nullptr;
	if (root == p || root == q)
		return root;
	
	// 在根结点的左右子树上寻找p和q的最近公共祖先
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	
	// 左子树上没有找到，则返回右子树的寻找结果。
	if (!left) return right;
	// 右子树上没有找到，则返回左子树的寻找结果。
	if (!right) return left;
	// 左子树和右子树都找到，而左子树和右子树的公共祖先为root，所以返回root。
	if (left && right) return root;
	
	return nullptr;
}

