/*
 * 题目：递增顺序查找树
 * 链接：https://leetcode-cn.com/problems/increasing-order-search-tree/
 */

#include <iostream>
#include <vector>

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

// 中序遍历打印元素
void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

// 中序遍历并将结点值加入数组中
void traverse(TreeNode *root, vector<int> &nums) {
	if (root) {
		traverse(root->left, nums);
		nums.push_back(root->val);
		traverse(root->right, nums);
	}
}

// 得到root的最右边叶子结点
TreeNode *increasingBST(TreeNode *root) {
	vector<int> nums;
	traverse(root, nums);

	// 建树
	auto *preroot = new TreeNode(-1);
	TreeNode *p = preroot;
	for (int n: nums) {
		auto *node = new TreeNode(n);
		p->right = node;
		p = p->right;
	}

	return preroot->right;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(5);
	auto t1 = new TreeNode(3);
	auto t2 = new TreeNode(6);
	auto t3 = new TreeNode(1);
	auto t4 = new TreeNode(4);
	auto t5 = new TreeNode(7);
	root->left = t1;
	root->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->right = t5;

	// 将二叉树展开为链表
	auto newroot = increasingBST(root);
	inorder(newroot);

	return 0;
}