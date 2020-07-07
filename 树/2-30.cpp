/*
 * 题目：在每个树行中找最大值
 * 链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x)
	{
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

vector<int> largestValues(TreeNode* root) {
	vector<int> nums;
	if (!root) return nums;
	
	queue<TreeNode*> q;
	q.push(root);
	
	// 层序遍历 
	while(!q.empty()) {
		int size = q.size();  // 当前层结点数
		int maxValue = q.front()->val;
		
		for(int i = 0; i < size; i++) {
			TreeNode* front = q.front();
			q.pop();
			maxValue = max(maxValue, front->val);
			
			if (front->left) q.push(front->left);
			if (front->right) q.push(front->right);
		}
		nums.push_back(maxValue);
	}
	
	return nums;
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(5);
	auto n1 = new TreeNode(4);
	auto n2 = new TreeNode(6);
	auto n3 = new TreeNode(2);
	auto n4 = new TreeNode(5);
	auto n5 = new TreeNode(7);
	auto n6 = new TreeNode(3);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	
	// 计算二叉树每行的最大值
	vector<int> nums = largestValues(root);
	for(int num: nums) 
		cout << num << " ";
	cout << endl;
	
	return 0;
}