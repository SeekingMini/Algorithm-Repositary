/*
 * 题目：环形链表 II
 * 链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/
 */

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	explicit ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};

ListNode *detectCycle(ListNode *head)
{
	if (!head) // 空链表
		return nullptr;

	// 定义快慢指针
	ListNode *fast = head;
	ListNode *slow = head;
	
	// 判断是否有环
	while (true) {
		if (fast == nullptr || fast->next == nullptr)
			return nullptr;
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) break;  // 快慢指针相遇说明有环
	}
	
	fast = head;
	while(slow != fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

int main()
{
	// 手动创建链表
	auto n1 = new ListNode(1);
	auto n2 = new ListNode(2);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	// 判断是否为环形链表
	ListNode *node = detectCycle(n1);
	cout << node->val << endl;

	return 0;
}