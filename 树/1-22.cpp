/*
 * 题目：把二叉搜索树转换为累加树
 * 链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	explicit TreeNode(int x)
	{
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

int sum = 0;

void traverse(TreeNode* root) {
	if (root) {
		traverse(root->left);
		cout << root->val << " ";
		traverse(root->right);
	}
}

TreeNode* convertBST(TreeNode* root) {
	if (root) {
		// 先累加右子树
		convertBST(root->right);
		sum += root->val;
		root->val = sum;
		// 再累加到左子树
		convertBST(root->left);
	}
	return root;
}

int main() {
	// 手动创建二叉树
	TreeNode* root = new TreeNode(5);
	TreeNode* n1 = new TreeNode(4);
	TreeNode* n2 = new TreeNode(13);
	TreeNode* n3 = new TreeNode(2);
	TreeNode* n4 = new TreeNode(6);
	TreeNode* n5 = new TreeNode(15);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n2->left = n4;
	n2->right = n5;
	
	// 累加
	convertBST(root);
	traverse(root);
	cout << endl;
	
	return 0;
}