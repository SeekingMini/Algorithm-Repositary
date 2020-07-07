/*
 * 题目：二进制链表转整数
 * 链接：https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 */

#include <stack>
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

int getDecimalValue(ListNode *head) {
	stack<int> st;
	int res = 0;
	ListNode *p = head;
	int base = 1;

	// 将结点值依次压入栈中
	while (p) {
		st.push(p->val);
		p = p->next;
	}

	while (!st.empty()) {
		res += base * st.top();
		st.pop();
		base *= 2;
	}

	return res;
}

int main() {
	// 手动创建链表
	auto n1 = new ListNode(1);
	auto n2 = new ListNode(0);
	auto n3 = new ListNode(0);
	auto n4 = new ListNode(1);
	auto n5 = new ListNode(0);
	auto n6 = new ListNode(0);
	auto n7 = new ListNode(1);
	auto n8 = new ListNode(1);
	auto n9 = new ListNode(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;

	// 删除
	int val = getDecimalValue(n1);
	cout << val << endl;

	return 0;
}