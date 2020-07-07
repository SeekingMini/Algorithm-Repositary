/*
 * 题目：反转链表 II
 * 链接：https://leetcode-cn.com/problems/reverse-linked-list-ii/
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

ListNode *reverseBetween(ListNode *head, int m, int n) {
	if (!head)  // 空链表
		return nullptr;
	if (!head->next)  // 只有1个结点
		return head;

	// 建立一个前置结点指向头结点
	auto *prehead = new ListNode(-1);
	prehead->next = head;
	
	stack<ListNode *> st;

	// p为指向m位置的结点，q为指向n位置的结点
	ListNode *prev = prehead;
	ListNode *p = prehead;
	ListNode *behind = prehead;
	ListNode *q = prehead;

	// prev移动到位置m前一个结点
	for (int i = 0; i < m - 1; ++i) {
		prev = prev->next;
		p = p->next;
	}
	p = p->next;

	// behind移动到位置n后一个结点
	for (int i = 0; i < n; ++i) {
		behind = behind->next;
		q = q->next;
	}
	behind = behind->next;
	
	// 把m到n位置的结点压入栈中
	for (int i = 0; i <= n - m; i++) {
		st.push(p);
		p = p->next;
	}

	// 反转
	while (!st.empty()) {
		prev->next = st.top();
		st.pop();
		prev = prev->next;
	}
	prev->next = behind;

	return prehead->next;
}

int main() {
	int m, n;
	cin >> m >> n;

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

	// 特定区间反转链表
	ListNode *head = reverseBetween(n1, m, n);
	ListNode *p = head;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	return 0;
}