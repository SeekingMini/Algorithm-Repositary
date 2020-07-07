/*
 * 题目：二叉树的锯齿形层次遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 */

#include <iostream>
#include <vector>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
	vector<vector<int>> values;
	if (!root)
		return values;

	int level = 0;  // 记录当前层数
	queue<TreeNode *> q;
	q.push(root);

	while (!q.empty()) {
		level++;
		vector<int> onerow;  // 一层的结点值
		int size = q.size();  // 当前层的结点数

		for (int i = 0; i < size; i++) {
			TreeNode *front = q.front();
			q.pop();
			
			// 奇数层正向添加元素，偶数层逆向添加元素
			if (level % 2 == 1) {
				onerow.push_back(front->val);
			} else {
				onerow.insert(onerow.begin(), front->val);
			}
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
		values.push_back(onerow);
	}
	return values;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(9);
	auto n2 = new TreeNode(20);
	auto n3 = new TreeNode(15);
	auto n4 = new TreeNode(7);
	root->left = n1;
	root->right = n2;
	n2->left = n3;
	n2->right = n4;

	// 计算左下角的值
	vector<vector<int>> values = zigzagLevelOrder(root);
	for (vector<int> onerow: values) {
		for (int num: onerow)
			cout << num << "\t";
		cout << endl;
	}

	return 0;
}
