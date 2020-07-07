/*
 * 题目：分隔链表
 * 链接：https://leetcode-cn.com/problems/partition-list/
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

// 前序遍历
void traverse(ListNode *head) {
	if (head) {
		cout << head->val << " ";
		traverse(head->next);
	}
}

ListNode *partition(ListNode *head, int x) {
	if (!head) return nullptr;

	// 新建两个链表，
	// 一个链表上的值全部小于x，一个链表上的值全部大于等于x。
	auto prev1 = new ListNode(-1);
	auto prev2 = new ListNode(-1);
	ListNode *p1 = prev1;
	ListNode *p2 = prev2;

	ListNode *p = head;
	while (p) {
		if (p->val < x) {
			p1->next = p;
			p1 = p1->next;
		} else {
			p2->next = p;
			p2 = p2->next;
		}
		p = p->next;
	}
	// 拼接两个链表
	p2->next = nullptr;
	p1->next = prev2->next;

	return prev1->next;
}

int main() {
	int k;
	cin >> k;

	// 手动创建链表
	auto head = new ListNode(1);
	auto n1 = new ListNode(4);
	auto n2 = new ListNode(3);
	auto n3 = new ListNode(2);
	auto n4 = new ListNode(5);
	auto n5 = new ListNode(2);
	auto n6 = new ListNode(7);
	auto n7 = new ListNode(1);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	// 分隔
	ListNode *newhead = partition(head, k);
	traverse(newhead);
	cout << endl;

	return 0;
}