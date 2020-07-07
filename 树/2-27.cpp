/*
 * 题目：打家劫舍 III
 * 链接：https://leetcode-cn.com/problems/house-robber-iii/
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

int rob(TreeNode* root) {

}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(2);
	auto n2 = new TreeNode(3);
	auto n3 = new TreeNode(3);
	auto n4 = new TreeNode(1);
	root->left = n1;
	root->right = n2;
	n1->right = n3;
	n2->right = n4;
	
	// 计算最高金额
	int money = rob(root);
	cout << money << endl;
	
	return 0;
}
