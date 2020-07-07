/*
 * 题目：二叉树中的列表
 * 链接：https://leetcode-cn.com/problems/linked-list-in-binary-tree/
 */

#include <iostream>
#include <vector>
#include <queue>

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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool check(ListNode *head, TreeNode *root)
{
	// 链表结点已经遍历完
	if (!head) return true;
	// 树的某一条路径已经遍历完但是链表还没遍历完
	if (!root) return false;

	if (head->val != root->val)
		return false;
	else
		return check(head->next, root->left) || check(head->next, root->right);
}

bool isSubPath(ListNode *head, TreeNode *root)
{
	if (!head) return true;
	if (!root) return false;

	return check(head, root) ||  // 先判断root为根结点存不存在符合要求的链表
		   // 再递归到左右子树分别进行判断
		   isSubPath(head, root->left) || isSubPath(head, root->right);
}

int main()
{
	// 手动创建二叉树
	TreeNode *root = new TreeNode(1);
	TreeNode *t1 = new TreeNode(4);
	TreeNode *t2 = new TreeNode(4);
	TreeNode *t3 = new TreeNode(2);
	TreeNode *t4 = new TreeNode(6);
	TreeNode *t5 = new TreeNode(8);
	TreeNode *t6 = new TreeNode(1);
	TreeNode *t7 = new TreeNode(3);
	root->left = t1;
	root->right = t2;
	t2->left = t3;
	t3->left = t4;
	t3->right = t5;
	t5->left = t6;
	t6->right = t7;

	// 手动创建链表
	ListNode *head = new ListNode(4);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(8);
	head->next = n1;
	n1->next = n2;

	// 检查列表
	bool flag = isSubPath(head, root);
	cout << flag << endl;

	return 0;
}