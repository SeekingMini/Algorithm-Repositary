/*
 * 题目：在二叉树中分配硬币
 * 链接：https://leetcode-cn.com/problems/distribute-coins-in-binary-tree/
 */

#include <iostream>
#include <cmath>

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

int compute(TreeNode *root, int &ans) {
	if (!root)
		return 0;

	int left = compute(root->left, ans);
	int right = compute(root->right, ans);
	ans += abs(left) + abs(right);

	return root->val - 1 + left + right;
}

int distributeCoins(TreeNode *root) {
	int ans = 0;
	compute(root, ans);

	return ans;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(0);
	auto n2 = new TreeNode(1);
	auto n3 = new TreeNode(0);
	root->left = n1;
	root->right = n2;
	n1->left = n3;

	// 计算移动次数
	int count = distributeCoins(root);
	cout << count << endl;

	return 0;
}