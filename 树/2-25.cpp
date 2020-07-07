/*
 * 题目：翻转等价二叉树
 * 链接：https://leetcode-cn.com/problems/flip-equivalent-binary-trees/
 */

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	explicit TreeNode(int v) {
		this->val = v;
		left = nullptr;
		right = nullptr;
	}
};

bool flipEquiv(TreeNode *root1, TreeNode *root2) {
	if (!root1 && !root2)  // 两者皆为空结点
		return true;
	if (!root1 || !root2)  // 一方为空结点
		return false;

	if (root1->val == root2->val) {
		return 
		// 如果不翻转，直接比较root1和root2的左右子树是否相等
		(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
		// 如果翻转，比较root1的左右子树和root2的右左子树是否相等
	    (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
	} else  
		return false;
}

int main() {
	// 手动创建二叉树
	auto r1 = new TreeNode(1);
	auto n11 = new TreeNode(2);
	auto n12 = new TreeNode(3);
	auto n13 = new TreeNode(4);
	auto n14 = new TreeNode(5);
	auto n15 = new TreeNode(6);
	r1->left = n11;
	r1->right = n12;
	n11->left = n13;
	n11->right = n14;
	n12->left = n15;

	auto r2 = new TreeNode(1);
	auto n21 = new TreeNode(3);
	auto n22 = new TreeNode(2);
	auto n23 = new TreeNode(6);
	auto n24 = new TreeNode(4);
	auto n25 = new TreeNode(5);
	r2->left = n21;
	r2->right = n22;
	n21->right = n23;
	n22->left = n24;
	n22->right = n25;

	// 判断是否等价
	bool flag = flipEquiv(r1, r2);
	cout << flag << endl;

	return 0;
}