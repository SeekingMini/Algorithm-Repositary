/*
 * 题目：删除链表的倒数第N个节点
 * 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
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

ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto *previous = new ListNode(0);
    previous->next = head;

    auto fast = previous;
    auto slow = previous;
    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return previous->next;
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

    // 删除
    auto p = removeNthFromEnd(n1, 2);
    while (p) {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;

    return 0;
}