/*
 * 题目：根据二叉树创建字符串
 * 链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree/
 */

#include <iostream>
#include <string>

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


string tree2str(TreeNode *t) {
	if (!t)
		return "";
	if (!t->right && !t->left)
		return to_string(t->val);
	if (!t->right)
		return to_string(t->val) + "(" + tree2str(t->left) + ")";
	return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(1);
	auto t1 = new TreeNode(2);
	auto t2 = new TreeNode(3);
	auto t3 = new TreeNode(4);
	root->left = t1;
	root->right = t2;
	t1->left = t3;

	// 将二叉树展开为链表
	string str = tree2str(root);
	cout << str << endl;

	return 0;
}