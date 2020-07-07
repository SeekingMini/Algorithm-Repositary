/*
 * 题目：重排链表
 * 链接：https://leetcode-cn.com/problems/reorder-list/
 */

#include <iostream>
#include <vector>
#include <stack>

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

void reorderList(ListNode *head) {
	if (!head) return;

	vector<ListNode *> nodes;
	ListNode *p = head;
	while (p) {
		nodes.push_back(p);
		p = p->next;
	}
	int len = nodes.size();  // 链表长度

	// 重建链表
	int mid;
	if (len % 2 == 0) {  // 链表长度为偶数
		mid = len / 2 - 1;  // 链表分为[0...mid-1]和[mid...len-1]
		auto *prev = new ListNode(-1);
		p = prev;
		for (int i = 0; i <= mid; i++) {
			p->next = nodes[i];
			p = p->next;
			p->next = nodes[len - 1 - i];
			p = p->next;
		}
		p->next = nullptr;
	} else {  // 链表长度为奇数
		mid = len / 2;  // 中间结点
		auto *prev = new ListNode(-1);
		p = prev;
		for (int i = 0; i< mid; i++) {
			p->next = nodes[i];
			p = p->next;
			p->next = nodes[len - 1 - i];
			p = p->next;
		}
		p->next = nodes[mid];
		p = p->next;
		p->next = nullptr;
	}
}

int main() {
	// 手动创建链表
	auto head = new ListNode(1);
	auto n1 = new ListNode(2);
	auto n2 = new ListNode(3);
	auto n3 = new ListNode(4);
	auto n4 = new ListNode(5);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	// 重排链表
	reorderList(head);
	traverse(head);
	cout << endl;

	return 0;
}
