/*
 * 题目：合并二叉树
 * 链接：https://leetcode-cn.com/problems/merge-two-binary-trees/
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

// 遍历二叉树
void traverse(TreeNode *root) {
	if (root) {
		cout << root->val << " ";
		traverse(root->left);
		traverse(root->right);
	}
}

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
	if (!t1)  // t1为空直接返回t2
		return t2;
	if (!t2)  // t2为空直接返回t1
		return t1;

	// t1和t2都存在，两者值相加
	t1->val += t2->val;
	// 合并左子树
	t1->left = mergeTrees(t1->left, t2->left);
	// 合并右子树
	t1->right = mergeTrees(t1->right, t2->right);

	return t1;
}

int main() {
	// 手动创建二叉树
	auto root1 = new TreeNode(1);
	auto n11 = new TreeNode(3);
	auto n12 = new TreeNode(4);
	root1->left = n11;
	root1->right = n12;

	auto root2 = new TreeNode(5);
	auto n21 = new TreeNode(1);
	auto n22 = new TreeNode(7);
	auto n23 = new TreeNode(0);
	auto n24 = new TreeNode(2);
	root2->left = n21;
	root2->right = n22;
	n21->left = n23;
	n21->right = n24;

	// 计算层数最深叶子节点的和
	auto mergedRoot = mergeTrees(root1, root2);
	traverse(mergedRoot);
	cout << endl;

	return 0;
}