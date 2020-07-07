/*
 * 题目：有序链表转换二叉搜索树
 * 链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

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

// 中序遍历
void traverse(TreeNode* root) {
	if (root) {
		traverse(root->left);
		cout << root->val << " ";
		traverse(root->right);
	}
}

// 有序数组构建二叉搜索树
TreeNode* construct(const vector<int> &nums, int low, int high) {
	if (low > high) return nullptr;

	int mid = low + (high - low) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = construct(nums, low, mid - 1);
	root->right = construct(nums, mid + 1, high);

	return root;
}

TreeNode* sortedListToBST(ListNode* head) {
	if (!head) return nullptr;
	ListNode* p = head;
	vector<int> nums;
	
	// 遍历链表，将结点值添加进数组
	while(p) {
		nums.push_back(p->val);
		p = p->next;
	}
	
	// 构建二叉搜索树
	int low = 0, high = nums.size() - 1;
	TreeNode* root = construct(nums, low, high);
	
	return root;
}

int main() {
	// 手动创建链表
	auto head = new ListNode(-10);
	auto n1 = new ListNode(-3);
	auto n2 = new ListNode(0);
	auto n3 = new ListNode(5);
	auto n4 = new ListNode(9);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	// 创建二叉搜索树
	TreeNode* root = sortedListToBST(head);
	traverse(root);
	cout << endl;
	
	return 0;
}
