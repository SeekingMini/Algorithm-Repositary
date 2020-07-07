/*
 * 题目：二叉树的完全性检验
 * 链接：https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree/
 */

#include <iostream>
#include <queue>

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

bool isCompleteTree(TreeNode *root) {
	if (!root)
		return true;

	queue<TreeNode *> q;
	q.push(root);
	bool hasToBeLeaf = false;

	// 逐层检验
	while (!q.empty()) {
		TreeNode *front = q.front();
		q.pop();

		// 有右子结点但没有左子结点
		if (!front->left && front->right)
			return false;

		// 前面出现过无右子节点的（只有左或左右都没有的），则后续所有节点必须为叶子节点。
		if (hasToBeLeaf) {
			if (front->left || front->right)
				return false;
		}

		if (front->left)
			q.push(front->left);
		if (front->right)
			q.push(front->right);
			// 没有右子结点，则后续结点须为叶子结点
		else
			hasToBeLeaf = true;
	}

	return true;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(1);
	auto n1 = new TreeNode(2);
	auto n2 = new TreeNode(3);
	auto n3 = new TreeNode(5);
	auto n4 = new TreeNode(7);
	auto n5 = new TreeNode(8);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->right = n5;

	// 检验完全性
	bool flag = isCompleteTree(root);
	cout << flag << endl;

	return 0;
}