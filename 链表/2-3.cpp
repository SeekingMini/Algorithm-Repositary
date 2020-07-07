/*
 * 题目：旋转链表
 * 链接：https://leetcode-cn.com/problems/rotate-list/
 */

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	explicit ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};

ListNode *rotateRight(ListNode *head, int k)
{
	if (!head)
		return head;
	if (!head->next) // 链表只有1个结点
		return head;

	// 使尾结点指向头结点建立环形链表
	ListNode *p = head;
	int length = 1; // 表示链表长度
	while (p->next)
	{
		length++;
		p = p->next;
	}
	p->next = head;

	// 遍历环形链表
	k = k % length;
	for (int i = 0; i < length - k; i++)
	{
		p = p->next;
	}
	ListNode *newhead = p->next;
	p->next = nullptr;

	return newhead;
}

int main()
{
	int k;
	cin >> k;

	// 手动创建链表
	auto n1 = new ListNode(1);
	auto n2 = new ListNode(2);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(4);
	auto n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	// 旋转链表
	ListNode *head = rotateRight(n1, k);
	auto p = head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}