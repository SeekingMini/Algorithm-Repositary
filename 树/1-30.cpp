/*
 * 题目：叶子相似的树
 * 链接：https://leetcode-cn.com/problems/leaf-similar-trees/
 */

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

void traverse(TreeNode *root, vector<int> &nums) {
	if (root) {
		// 叶子结点
		if (!root->left && !root->right) nums.push_back(root->val);
		traverse(root->left, nums);
		traverse(root->right, nums);
	}
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
	vector<int> nums1, nums2;

	traverse(root1, nums1);
	traverse(root2, nums2);

	// 判断
	return nums1 == nums2;
}