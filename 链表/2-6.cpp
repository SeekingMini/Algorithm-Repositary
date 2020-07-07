/*
 * 题目：两两交换链表中的节点
 * 链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 */

#include <iostream>
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

ListNode *swapPairs(ListNode *head) {
	if (!head)  // 空结点
		return nullptr;
	if (!head->next)  // 只有1个结点
		return head;

	stack<ListNode *> st;
	int count = 0;  // 链表的长度

	// 将结点压入栈中
	ListNode *p = head;
	while (p) {
		st.push(p);
		p = p->next;
		count++;
	}

	// 两两交换
	auto *prev = new ListNode(-1);
	if (count % 2 == 1) {
		prev->next = st.top();
		st.pop();
	}
	while (!st.empty()) {
		ListNode *p1 = st.top();
		st.pop();
		ListNode *p2 = st.top();
		st.pop();
		p2->next = prev->next;
		prev->next = p1;
		p1->next = p2;
	}

	return prev->next;
}

int main() {
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

	// 两两交换
	ListNode *head = swapPairs(n1);
	ListNode *p = head;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	return 0;
}