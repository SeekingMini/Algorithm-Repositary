/*
 * 题目：检查子树
 * 链接：https://leetcode-cn.com/problems/check-subtree-lcci/
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

// 判断t1和t2是否相同
bool isSameTree(TreeNode *t1, TreeNode *t2) {
	if (!t1 && !t2)
		return true;
	if ((t1 && !t2) || (!t1 && t2))
		return false;

	if (t1->val == t2->val)
		return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
	else return false;
}

bool checkSubTree(TreeNode *t1, TreeNode *t2) {
	if (!t1 && !t2)  // 两者都是空树
		return true;

	// t1不空而t2不空
	if (t1 && !t2) return true;
	// t1为空而t2不空
	if (!t1 && t2) return false;

	return isSameTree(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
}

int main() {
	// 手动创建二叉树
	auto root1 = new TreeNode(1);
	auto n11 = new TreeNode(3);
	auto n12 = new TreeNode(4);
	auto n13 = new TreeNode(2);
	auto n14 = new TreeNode(5);
	root1->left = n11;
	root1->right = n12;
	n11->left = n13;
	n11->right = n14;

	auto root2 = new TreeNode(3);
	auto n21 = new TreeNode(2);
	auto n22 = new TreeNode(5);
	root2->left = n21;
	root2->right = n22;

	// 判断t1的某个子树是否和t2一样
	bool flag = checkSubTree(root1, root2);
	cout << flag << endl;

	return 0;
}