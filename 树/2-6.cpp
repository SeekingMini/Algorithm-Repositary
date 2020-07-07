/*
 * 题目：删除给定值的叶子节点
 * 链接：https://leetcode-cn.com/problems/delete-leaves-with-a-given-value/
 */

#include <iostream>
#include <queue>

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

void traverse(TreeNode* root) {
	if (root) {
		cout << root->val << "\t";
		traverse(root->left);
		traverse(root->right);
	}
}

void deleteNodes(TreeNode* root, bool &flag, const int target) {
	if (!root) return;
		
	// 遇到符合要求的子结点
	if (!root->left && !root->right && root->val == target) {
		flag = true;
	} else {
		if (root->left) {
			deleteNodes(root->left, flag, target);
			// 需要删除叶子结点
			if (flag) {
				TreeNode* child = root->left;
				delete child;
				root->left = nullptr;
			}
			// 检查root是否需要删除
			if (!root->left && !root->right && root->val == target)
				flag = true;
			else 
				flag = false;
		}
		if (root->right) {
			deleteNodes(root->right, flag, target);
			if (flag) {
				TreeNode* child = root->right;
				delete child;
				root->right = nullptr;
			}
			if (!root->left && !root->right && root->val == target)
				flag = true;
			else 
				flag = false;
		}
	}
	// 回溯
}

TreeNode* removeLeafNodes(TreeNode* root, int target) {
	bool flag = false;
	deleteNodes(root, flag, target);
	
	// 删完结点后，如果root结点值也等于target，说明它是最后一个叶子结点。
	if (root->val == target) {
		return nullptr;
	}
	return root;
}

int main() {
	int target;
	cin >> target;
	
	// 手动创建二叉树
	auto root = new TreeNode(2);
	auto n1 = new TreeNode(1);
	auto n2 = new TreeNode(2);
	root->left = n1;
	root->right = n2;

	// 删除给定值的叶子结点
	TreeNode* newroot = removeLeafNodes(root, target);
	traverse(newroot);

	return 0;
}