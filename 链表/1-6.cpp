/*
 * 题目：移除重复结点
 * 链表：https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
 */

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

ListNode *removeDuplicateNodes(ListNode *head) {
	if (!head) return nullptr;

	ListNode *p = head;
	unordered_set<int> set;

	while (p && p->next) {
		set.insert(p->val);
		if (set.count(p->next->val) != 0)
			p->next = p->next->next;
		else p = p->next;
	}
	return head;
}

int main() {
	// 手动创建链表
	auto head = new ListNode(1);
	auto n1 = new ListNode(2);
	auto n2 = new ListNode(3);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(1);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	// 去除重复结点
	ListNode *newhead = removeDuplicateNodes(head);
	auto p = newhead;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}
