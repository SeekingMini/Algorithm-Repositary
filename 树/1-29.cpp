/*
 * 题目：修剪二叉搜索树
 * 链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree/
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
		traverse(root->left);
		cout << root->val << " ";
		traverse(root->right);
	}
}

TreeNode *trimBST(TreeNode *root, int L, int R) {
	if (!root) return nullptr;

	// 处理左子树，把root及root右子树剪掉
	if (root->val > R) return trimBST(root->left, L, R);
	// 处理右子树，把root及root左子树剪掉
	if (root->val < L) return trimBST(root->right, L, R);
	// root符合条件，递归到左右子树进行修剪
	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);

	return root;
}

int main() {
	int L, R;
	cin >> L >> R;

	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(0);
	auto n2 = new TreeNode(4);
	auto n3 = new TreeNode(2);
	auto n4 = new TreeNode(1);
	root->left = n1;
	root->right = n2;
	n1->right = n3;
	n3->left = n4;

	// 构造高度最小的二叉搜索树
	auto newroot = trimBST(root, L, R);
	traverse(root);
	cout << endl;

	return 0;
}