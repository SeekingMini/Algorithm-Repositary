/*
 * 题目：最大二叉树
 * 链接：https://leetcode-cn.com/problems/maximum-binary-tree/
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

// 遍历二叉树
void traverse(TreeNode *root) {
	if (root) {
		cout << root->val << " ";
		traverse(root->left);
		traverse(root->right);
	}
}

// 得到[low,high]范围内的最大数的索引
int getMaxNumIndex(const vector<int> &nums, int low, int high) {
	int idx = low;
	for (int i = low; i <= high; i++) {
		if (nums[idx] < nums[i])
			idx = i;
	}
	
	return idx;
}

// 构建二叉树
TreeNode *construct(const vector<int> &nums, int low, int high) {
	if (low > high) return nullptr;

	int max_idx = getMaxNumIndex(nums, low, high);
	auto *root = new TreeNode(nums[max_idx]);
	
	root->left = construct(nums, low, max_idx - 1);
	root->right = construct(nums, max_idx + 1, high);

	return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
	// 数组最大索引
	int high = nums.size() - 1;
	int low = 0;
	
	return construct(nums, low, high);
}

int main() {
	// 创建数组
	int n;
	vector<int> nums;
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 创建特定深度链表
	TreeNode *root = constructMaximumBinaryTree(nums);
	traverse(root);
	cout << endl;

	return 0;
}