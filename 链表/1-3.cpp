/*
 * 题目：回文链表
 * 链接：https://leetcode-cn.com/problems/palindrome-linked-list/
 */

#include <iostream>
#include <stack>

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

bool isPalindrome(ListNode *head)
{
    if (!head) // 空链表
        return true;
    if (!head->next) // 链表只有1个结点
        return true;

    stack<int> st;
    ListNode *p = head;

    // 计算链表长度
    int length = 0;
    while (p)
    {
        length++;
        st.push(p->val);  // 将结点压入栈中
        p = p->next;
    }

    p = head;
    int mid = length / 2;
    for (int i = 0; i < mid; i++)
    {
        if (p->val != st.top())
            return false;
        st.pop();
        p = p->next;
    }
    return true;
}

int main()
{
    // 手动创建链表
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(2);
    auto n5 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // 判断是否为回文链表
    bool flag = isPalindrome(n1);
    cout << flag << endl;

    return 0;
}