/*
 * 题目：特定深度节点链表
 * 链接：https://leetcode-cn.com/problems/list-of-depth-lcci/
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  explicit TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
  }
};

struct ListNode {
  int val;
  ListNode *next;

  explicit ListNode(int x) {
    val = x;
    next = nullptr;
  }
};

vector<ListNode *> listOfDepth(TreeNode *tree) {
  vector<ListNode *> heads;
  if (!tree) return heads;

  queue<TreeNode *> q;
  q.push(tree);

  while (!q.empty()) {
    // 链表头部结点的前驱结点
    auto *prev = new ListNode(-1);
    ListNode *p = prev;

    int size = q.size();  // 当前层的结点数

    for (int i = 0; i < size; i++) {
      TreeNode *front = q.front();
      q.pop();
      
      p->next = new ListNode(front->val);
      p = p->next;

      if (front->left) q.push(front->left);
      if (front->right) q.push(front->right);
    }
    if (prev->next) heads.push_back(prev->next);
  }

  return heads;
}

int main() {
  // 手动创建二叉树
  auto root = new TreeNode(10);
  auto t1 = new TreeNode(9);
  auto t2 = new TreeNode(12);
  auto t3 = new TreeNode(7);
  auto t4 = new TreeNode(11);
  auto t5 = new TreeNode(14);
  auto t6 = new TreeNode(4);
  auto t7 = new TreeNode(8);
  root->left = t1;
  root->right = t2;
  t1->left = t3;
  t2->left = t4;
  t2->right = t5;
  t3->left = t6;
  t3->right = t7;

  // 创建特定深度链表
  vector<ListNode *> heads = listOfDepth(root);
  for (ListNode *head : heads) {
    auto p = head;
    while (p) {
      cout << p->val << " ";
      p = p->next;
    }
    cout << endl;
  }

  return 0;
}