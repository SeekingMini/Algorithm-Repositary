/*
 * 题目：统计二叉树中好节点的数目
 * 链接：https://leetcode-cn.com/problems/count-good-nodes-in-binary-tree/
 */

#include <iostream>

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

void traverse(TreeNode *root, int max_value, int &count) {
	if (!root)
		return;

	if (max_value <= root->val) count++;
	// max_value是一个状态量，在遍历二叉树时通过和root值进行比较不停地更新
	max_value = max(max_value, root->val);
	
	traverse(root->left, max_value, count);
	traverse(root->right, max_value, count);
}

int goodNodes(TreeNode *root) {
	int count = 0;
	traverse(root, root->val, count);

	return count;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(1);
	auto n2 = new TreeNode(4);
	auto n3 = new TreeNode(3);
	auto n4 = new TreeNode(1);
	auto n5 = new TreeNode(5);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n2->left = n4;
	n2->right = n5;

	// 计算好结点的个数
	int count = goodNodes(root);
	cout << count << endl;

	return 0;
}