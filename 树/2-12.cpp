/*
 * 题目：完全二叉树的节点个数
 * 链接：https://leetcode-cn.com/problems/count-complete-tree-nodes/
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

// 解法1：层序遍历
// 层序遍历二叉树，一层一层计算二叉树结点数。 
int countNodes_method1(TreeNode *root) {
	if (!root)
		return 0;

	int count = 0;
	queue<TreeNode *> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();
		count += size;
		for (int i = 0; i < size; i++) {
			TreeNode *front = q.front();
			q.pop();
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
	}

	return count;
}

// 解法2：深度优先遍历
// 利用二叉树的性质：
// 1. 如果root左子树和root右子树深度相同，则说明左子树为满二叉树；
// 2. 如果root左子树深度大于root右子树深度，则说明右子树为满二叉树。
int depth(TreeNode* root) {
	int level = 0;
	while(root) {
		level++;
		root = root->left;
	}
	return level;
}

int countNodes_method2(TreeNode *root) {
	if (!root)	return 0;
	
	// 分别计算左右子树深度
	int left = depth(root->left);
	int right = depth(root->right);
	
	// 比较深度
	if (left == right) {
		return (1 << left) + countNodes_method2(root->right);
	} else {
		return (1 << right) + countNodes_method2(root->left);
	}
}


int main() {
	// 手动创建二叉树
	auto root = new TreeNode(-10);
	auto t1 = new TreeNode(9);
	auto t2 = new TreeNode(20);
	auto t3 = new TreeNode(15);
	auto t4 = new TreeNode(7);
	auto t5 = new TreeNode(6);
	root->left = t1;
	root->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->left = t5;

	// 计算二叉树的节点个数
	int count = countNodes_method2(root);
	cout << count << endl;

	return 0;
}