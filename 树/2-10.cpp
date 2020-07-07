/*
 * 题目：求根到叶子节点数字之和
 * 链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
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

void computePaths(TreeNode *root, int sum, int &totalSum)
{
	if (!root) // 遇到空结点
		return;

	sum = sum * 10 + root->val;
	// 遇到叶子结点，总和累加
	if (!root->left && !root->right)
		totalSum += sum;
	else
	{
		// 遇到非叶子结点，继续向左右子树遍历
		computePaths(root->left, sum, totalSum);
		computePaths(root->right, sum, totalSum);
	}
}

int sumNumbers(TreeNode *root)
{
	int sum = 0, totalSum = 0;
	computePaths(root, sum, totalSum);

	return totalSum;
}

int main()
{
	// 手动创建二叉树
	auto root = new TreeNode(1);
	auto n1 = new TreeNode(2);
	auto n2 = new TreeNode(3);
	root->left = n1;
	root->right = n2;

	// 计算二进制之和
	int sum = sumNumbers(root);
	cout << sum << endl;

	return 0;
}