/*
 * 题目：首个共同祖先
 * 链接：https://leetcode-cn.com/problems/first-common-ancestor-lcci/
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!root)
		return nullptr;
	if (root == q || root == p)
		return root;

	// 从root的左右子树上寻找公共祖先
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);

	if (!left)
		return right;
	if (!right)
		return left;
	return root;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(5);
	auto n2 = new TreeNode(1);
	auto n3 = new TreeNode(6);
	auto n4 = new TreeNode(2);
	auto n5 = new TreeNode(0);
	auto n6 = new TreeNode(8);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;

	// 插入结点
	auto p = n3;
	auto q = n2;
	TreeNode *ancestor = lowestCommonAncestor(root, p, q);
	cout << ancestor->val << endl;

	return 0;
}