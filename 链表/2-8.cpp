/*
 * 题目：奇偶链表
 * 链接：https://leetcode-cn.com/problems/odd-even-linked-list/
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

ListNode *oddEvenList(ListNode *head) {
	if (!head)  // 空链表
		return nullptr;
	if (!head->next)  // 链表只有1个结点
		return nullptr;
	if (!head->next->next)  // 链表有2个结点
		return head;

	auto *prev = new ListNode(-1);
	prev->next = head;
	ListNode *second = head->next;  // 链表第2个结点

	ListNode *odd = head;  // 链表第1个结点
	ListNode *even = head->next;  // 链表第2个结点
	int count = 1;
	ListNode *p = head->next->next;  // 从链表第3个结点开始

	while (p) {
		ListNode *q = p->next;
		if (count % 2 == 1) {
			odd->next = p;
			odd = odd->next;
			p = q;
		} else {
			even->next = p;
			even = even->next;
			p = q;
		}
		count++;
	}
	even->next = nullptr;
	odd->next = second;

	return prev->next;
}

int main() {
	// 手动创建链表
	auto n1 = new ListNode(2);
	auto n2 = new ListNode(1);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(5);
	auto n5 = new ListNode(6);
	auto n6 = new ListNode(4);
	auto n7 = new ListNode(7);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	// 把所有的奇数节点和偶数节点分别排在一起
	ListNode *head = oddEvenList(n1);
	ListNode *p = head;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	return 0;
}