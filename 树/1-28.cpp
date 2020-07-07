/*
 * 题目：最小高度树
 * 链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci/
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

// 中序遍历二叉树
void traverse(TreeNode *root) {
	if (root) {
		traverse(root->left);
		cout << root->val << " ";
		traverse(root->right);
	}
}

TreeNode *construct(int low, int high, const vector<int> &nums) {
	if (low > high)
		return nullptr;
	
	// 构造根结点，根结点的值为数组中间元素
	int mid = low + (high - low) / 2;
	auto root = new TreeNode(nums[mid]);
	// 递归构造左右子树（类似于二分查找）
	root->left = construct(low, mid - 1, nums);
	root->right = construct(mid + 1, high, nums);

	return root;
}

TreeNode *sortedArrayToBST(const vector<int> &nums) {
	int low = 0;
	int high = nums.size() - 1;

	return construct(low, high, nums);
}

int main() {
	vector<int> nums;
	int n;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n')
			break;
	}

	// 构造高度最小的二叉搜索树
	TreeNode *root = sortedArrayToBST(nums);
	traverse(root);
	cout << endl;

	return 0;
}