/*
 * 题目：反转链表
 * 链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

ListNode *reverseList(ListNode *head) {
	if (!head)  // 空链表
		return nullptr;
	if (!head->next)  // 只有1个结点
		return head;

	ListNode *p1 = head;
	ListNode *p2 = head->next;
	head->next = nullptr;

	while (p2) {
		ListNode *p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}

int main() {
	// 手动创建链表
	auto n1 = new ListNode(1);
	auto n2 = new ListNode(2);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	// 反转链表
	ListNode *head = reverseList(n1);
	ListNode *p = head;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	return 0;
}