/*
 * 题目：打家劫舍 III
 * 链接：https://leetcode-cn.com/problems/house-robber-iii/
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	explicit TreeNode(int v)
	{
		this->val = v;
		left = nullptr;
		right = nullptr;
	}
};

// arr[0]表示不抢root，能得到的最大金额；
// arr[1]表示抢root，能得到的最大金额。
vector<int> dp(TreeNode* root) {
	if (!root) return vector<int>(2, 0);
	
	// 分别计算左右子树上可以获得的最大金额
	vector<int> left = dp(root->left);
	vector<int> right = dp(root->right);
	
	// 选择抢root，则下家不能抢
	int val1 = root->val + left[0] + right[0];
	// 选择不抢root，则下家可抢可不抢，需要比较数值大小
	int val2 = max(left[0], left[1]) + max(right[0], right[1]);
	
	vector<int> vals;
	vals.push_back(val2);
	vals.push_back(val1);
	
	return vals;
}

int rob(TreeNode* root) {
	vector<int> vals = dp(root);
	
	return max(vals[0], vals[1]);
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(3);
	auto n1 = new TreeNode(4);
	auto n2 = new TreeNode(5);
	auto n3 = new TreeNode(1);
	auto n4 = new TreeNode(3);
	auto n5 = new TreeNode(1);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->right = n5;
	
	// 计算最大金额
	int val = rob(root);
	cout << val << endl;
	
	return 0;
}