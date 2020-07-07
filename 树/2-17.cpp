/*
 * 题目：二叉树剪枝
 * 链接：https://leetcode-cn.com/problems/binary-tree-pruning/
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

// 中序遍历二叉树
void traverse(TreeNode *root) {
	if (root) {
		cout << root->val << " ";
		traverse(root->left);
		traverse(root->right);
	}
}

// 检查以root为根结点的子树（包括自身）中是否含有1
bool checkHas1(TreeNode *root) {
	if (!root)
		return false;

	return root->val == 1 || checkHas1(root->left) || checkHas1(root->right);
}

TreeNode *pruneTree(TreeNode *root) {
	if (!root)
		return nullptr;

	// 检查root左右子树是否含有1
	bool leftSubTreeHas1 = checkHas1(root->left);
	bool rightSubTreeHas1 = checkHas1(root->right);
	
	// 左子树全是0
	if (!leftSubTreeHas1) 
		root->left = nullptr;
	root->left = pruneTree(root->left);  // 递归到左子树进行剪枝
	// 右子树全是0
	if (!rightSubTreeHas1) 
		root->right = nullptr;
	root->right = pruneTree(root->right);  // 递归到右子树进行剪枝

	// 剪到最后只剩root结点且root值为0
	if (root->val == 0 && !root->left && !root->right)
		return nullptr;

	return root;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(1);
	auto n1 = new TreeNode(0);
	auto n2 = new TreeNode(1);
	auto n3 = new TreeNode(0);
	auto n4 = new TreeNode(0);
	auto n5 = new TreeNode(0);
	auto n6 = new TreeNode(1);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;

	// 插入结点
	TreeNode *newroot = pruneTree(root);
	traverse(newroot);
	cout << endl;

	return 0;
}