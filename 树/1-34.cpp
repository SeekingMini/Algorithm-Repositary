/*
 * 题目：二叉树的堂兄弟节点
 * 链接：https://leetcode-cn.com/problems/cousins-in-binary-tree/
 */

#include <iostream>
#include <queue>
#include <unordered_map>
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

bool isCousins(TreeNode *root, int x, int y) {
  queue<TreeNode *> q;
  unordered_map<int, int> map;  // map[child] = parent
  q.push(root);

  bool flag = false;
  while (!q.empty()) {
    vector<int> nums;
    int size = q.size();  // 当前层的结点数

    // 把同一层的结点全部添加进队列
    for (int i = 0; i < size; i++) {
      TreeNode *front = q.front();
      q.pop();
      if (front->left) {
        q.push(front->left);
        map[front->left->val] = front->val;
        nums.push_back(front->left->val);
      }
      if (front->right) {
        q.push(front->right);
        map[front->right->val] = front->val;
        nums.push_back(front->right->val);
      }
    }

    // 查找x、y
    if (nums.size() >= 2) {
      bool found = false;
      bool xfound = false;
      bool yfound = false;
      for (int num : nums) {
        if (num == x) {
          xfound = true;
          break;
        }
      }
      for (int num : nums) {
        if (num == y) {
          yfound = true;
          break;
        }
      }
      found = xfound && yfound;
      if (found == true && map[x] != map[y]) {
        flag = true;
        break;
      }
    }
  }

  return flag;
}

int main() {
  int x, y;
  cin >> x >> y;

  // 手动创建二叉树
  auto root = new TreeNode(5);
  auto n1 = new TreeNode(3);
  auto n2 = new TreeNode(6);
  auto n3 = new TreeNode(2);
  auto n4 = new TreeNode(4);
  auto n5 = new TreeNode(7);
  root->left = n1;
  root->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->right = n5;

  // 计算二进制之和
  bool flag = isCousins(root, x, y);
  cout << flag << endl;

  return 0;
}