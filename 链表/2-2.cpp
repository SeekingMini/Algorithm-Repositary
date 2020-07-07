/*
 * 题目：删除排序链表中的重复元素 II
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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

ListNode *deleteDuplicates(ListNode *head) {
	if (!head)  // 空链表
		return head;

	ListNode *prev = new ListNode(-1);
	prev->next = head;

	ListNode *p = prev;
	ListNode *slow = head;
	ListNode *fast = head->next;

	while (fast) {
		if (slow->val != fast->val) {
			p = slow;
			slow = slow->next;
			fast = fast->next;
		} else {
			// 先删fast
			while (fast) {
				if (slow->val == fast->val) {
					ListNode *t = fast->next;
					slow->next = t;
					delete fast;
					fast = t;
				} else {
					break;
				}
			}
			// 再删slow
			p->next = fast;
			delete slow;
			slow = fast;
			if (!fast)
				break;
			else
				fast = fast->next;
		}
	}
	return prev->next;
}

int main() {
	// 手动创建链表
	auto n1 = new ListNode(1);
	auto n2 = new ListNode(1);
	auto n3 = new ListNode(1);
	auto n4 = new ListNode(2);
	auto n5 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	// 删除
	ListNode *head = deleteDuplicates(n1);
	auto p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}