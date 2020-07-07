/*
 * 题目：环形链表
 * 链接：https://leetcode-cn.com/problems/linked-list-cycle/
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

bool hasCycle(ListNode *head) {
    if (!head)  // 空链表
        return false;

    // 定义快慢指针
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
        else
            return false;
        if (fast == slow) {
            return fast != nullptr;
        }
    }
    return false;
}

int main() {
    // 手动创建链表
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // 判断是否为环形链表
    bool flag = hasCycle(n1);
    cout << flag << endl;

    return 0;
}