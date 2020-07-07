/*
 * 题目：从根到叶的二进制数之和
 * 链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/
 */

#include <iostream>
#include <stack>

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

void computePaths(TreeNode *root, int &sum, stack<int> &st) {
	if (!root)  // 遇到空结点
		return;

	st.push(root->val);
	// 遇到叶子结点，需要计算一条路径上的二进制和
	if (!root->left && !root->right) {
		stack<int> copiedStack = st;
		int base = 1;
		int onePathSum = 0;
		while (!copiedStack.empty()) {
			onePathSum += (copiedStack.top() * base);
			copiedStack.pop();
			base *= 2;
		}
		sum += onePathSum;
	} else {
		// 遇到非叶子结点，继续向左右子树遍历
		computePaths(root->left, sum, st);
		computePaths(root->right, sum, st);
	}
	st.pop();  // 弹出叶子结点并回溯
}

int sumRootToLeaf(TreeNode *root) {
	int sum = 0;
	stack<int> st;
	computePaths(root, sum, st);

	return sum;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(1);
	auto n1 = new TreeNode(0);
	auto n2 = new TreeNode(1);
	auto n3 = new TreeNode(0);
	auto n4 = new TreeNode(1);
	auto n5 = new TreeNode(0);
	auto n6 = new TreeNode(1);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;

	// 计算二进制之和
	int sum = sumRootToLeaf(root);
	cout << sum << endl;

	return 0;

}