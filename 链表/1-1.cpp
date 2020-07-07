/* 
 * 题目：删除排序链表中的重复元素
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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
	if (!head || !head->next)  // 链表为空或者只有一个结点
		return head;

	// 定义快慢指针
	auto slow = head;
	auto fast = head->next;

	while (fast) {
		if (slow->val == fast->val) {
			auto p = fast->next;
			slow->next = p;
			delete fast;  // 释放空间
			fast = p;
		} else {
			fast = fast->next;
			slow = slow->next;
		}
	}
	return head;
}

int main() {
	// 手动创建链表
	auto n1 = new ListNode(1);
	auto n2 = new ListNode(1);
	auto n3 = new ListNode(2);
	n1->next = n2;
	n2->next = n3;

	// 删除重复元素
	ListNode *head = deleteDuplicates(n1);
	auto p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}

