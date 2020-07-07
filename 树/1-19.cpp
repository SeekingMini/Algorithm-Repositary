/*
 * 题目：二叉搜索树的最小绝对差
 * 链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 */

#include <iostream>
#include <vector>

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

// 中序遍历
void traverse(TreeNode *root, vector<int> &nums)
{
	if (root)
	{
		traverse(root->left, nums);
		nums.push_back(root->val);
		traverse(root->right, nums);
	}
}

int getMinimumDifference(TreeNode *root)
{
	vector<int> nums;
	traverse(root, nums);

	int diff = INT32_MAX;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		diff = min(diff, nums[i + 1] - nums[i]);
	}

	return diff;
}

int main()
{
	// 手动创建二叉树
	auto *root = new TreeNode(1);
	auto *n1 = new TreeNode(3);
	auto *n2 = new TreeNode(2);
	root->right = n1;
	n1->left = n2;

	// 计算二叉搜索树的最小绝对差
	int res = getMinimumDifference(root);
	cout << res << endl;

	return 0;
}