/*
 * 题目：两数相加
 * 链接：https://leetcode-cn.com/problems/add-two-numbers/
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // 一方为空链表
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    // 分别计算l1和l2的长度
    int len_l1 = 1;
    int len_l2 = 1;
    ListNode *p_l1 = l1;
    ListNode *p_l2 = l2;
    while (p_l1->next) {
        len_l1++;
        p_l1 = p_l1->next;
    }
    while (p_l2->next) {
        len_l2++;
        p_l2 = p_l2->next;
    }

    // 比较长度并在短链表尾部补0
    if (len_l1 > len_l2) // l2长度短
    {
        // 在l2尾部添加0结点
        for (int i = 0; i < len_l1 - len_l2; i++) {
            p_l2->next = new ListNode(0);
            p_l2 = p_l2->next;
        }
    } else {
        // 在l1尾部添加0结点
        for (int i = 0; i < len_l2 - len_l1; i++) {
            p_l1->next = new ListNode(0);
            p_l1 = p_l1->next;
        }
    }

    // 链表相加
    bool carry = false;
    p_l1 = l1;
    p_l2 = l2;
    auto *l3 = new ListNode(-1);  // 需要返回的新链表
    ListNode *p = l3;
    int s;  // 记录相加结果
    while (p_l1 && p_l2) {
        s = carry + p_l1->val + p_l2->val;
        p->next = new ListNode(s % 10);
        carry = (s >= 10);
        p = p->next;
        p_l1 = p_l1->next;
        p_l2 = p_l2->next;
    }
    if (carry)
        p->next = new ListNode(1);

    return l3->next;
}

int main() {
    // 手动创建链表
    auto n11 = new ListNode(2);
    auto n12 = new ListNode(4);
    auto n13 = new ListNode(3);
    n11->next = n12;
    n12->next = n13;

    auto n21 = new ListNode(5);
    auto n22 = new ListNode(6);
    auto n23 = new ListNode(4);
    n21->next = n22;
    n22->next = n23;

    // 旋转链表
    ListNode *head = addTwoNumbers(n11, n21);
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}