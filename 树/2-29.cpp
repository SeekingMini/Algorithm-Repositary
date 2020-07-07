/*
 * 题目：删除二叉搜索树中的节点
 * 链接：https://leetcode-cn.com/problems/delete-node-in-a-bst 
 */

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x)
	{
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

void traverse(TreeNode* root) {
	if (root) {
		traverse(root->left);
		cout << root->val << " ";
		traverse(root->right);
	}
}

TreeNode* deleteNode(TreeNode* root, int key) {
	if (!root) return nullptr;
	
	// key小于root值，递归到左子树去寻找
	if (key < root->val) {
		root->left = deleteNode(root->left, key);
		return root;
	}
	// key大于root值，递归到左子树去寻找
	if (key > root->val) {
		root->right = deleteNode(root->right, key);
		return root;
	}
	
	// 找到key且没有左子树，右子树接上
	if (!root->left) {
		TreeNode* right = root->right;
		delete root;  // 释放根结点空间
		return right;
	}
	// 找到key且没有右子树，左子树接上
	if (!root->right) {
		TreeNode* left = root->left;
		delete root;  // 释放根结点空间
		return left;
	}
	
	// 左右子树都存在，首先找到右子树中的最小结点
	TreeNode* node = root->right;
	while (node->left) node = node->left;
	// 为了简化，直接交换值而不交换结点
	int tmp = root->val;
	root->val = node->val;
	node->val = tmp;
	// 递归到右子树去删除结点
	root->right = deleteNode(root->right, key);
	return root;
}

int main() {
	int key;
	cin >> key;
	
	// 手动创建二叉树
	auto root = new TreeNode(5);
	auto n1 = new TreeNode(3);
	auto n2 = new TreeNode(6);
	auto n3 = new TreeNode(2);
	auto n4 = new TreeNode(4);
	auto n5 = new TreeNode(7);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->right = n5;
	
	// 删除结点
	TreeNode* newroot = deleteNode(root, key);
	traverse(newroot);
	cout << endl;
	
	return 0;
}
