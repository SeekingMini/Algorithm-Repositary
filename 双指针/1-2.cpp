/*
 * 题目：删除排序链表中的重复元素
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

ListNode *deleteDuplicates(ListNode *head) {
	if (!head)
		return nullptr;
	// 双指针
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast) {
		// fast不重复
		if (fast->val != slow->val) {
			slow->next = fast;
			slow = slow->next;
		}
		fast = fast->next;
	}

	// 断开与后面重复元素的连接
	slow->next = nullptr;
	return head;
}

int main() {
	// 手动创建链表
	auto head = new ListNode(1);
	auto n1 = new ListNode(2);
	auto n2 = new ListNode(-3);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(4);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	// 删除重复元素
	ListNode *newhead = deleteDuplicates(head);
	ListNode *p = newhead;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	return 0;
}