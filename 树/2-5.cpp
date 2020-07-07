/*
 * 题目：找树左下角的值
 * 链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 */

#include <iostream>
#include <queue>

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

// 求二叉树层数
int depth(TreeNode *root) {
	if (!root) return 0;

	return 1 + max(depth(root->left), depth(root->right));
}

// 解法1：层序遍历
// 使用层序遍历，当遍历到最后一层时，将队列的头部元素作为结果返回即可。
int findBottomLeftValue_method1(TreeNode *root) {
	int res = 0;
	int height = depth(root);  // 求二叉树的高度（层数）
	queue<TreeNode *> q;

	int h = 0;
	q.push(root);
	while (!q.empty()) {
		int currentSize = q.size();  // 当前层的结点数
		h++;
		
		// 遍历到最后一层
		if (h == height) {
			res = q.front()->val;
			break;
		} else {
			for (int i = 0; i < currentSize; i++) {
				TreeNode *node = q.front();
				q.pop();
				
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
	}

	return res;
}

// 解法2：深度优先遍历
// 对前序遍历进行改造，顺序变为【中->右->左】，遍历到最后一层时res即为结果。
// 因为顺序是从右到左，所以最后的res一定是树左下角的值。
void dfs(TreeNode* root, int &res, int h, int height) {
	if (!root) return;
	
	// 遍历到最后一层
	if (h == height) res = root->val;
	else {
		dfs(root->right, res, h + 1, height);
		dfs(root->left, res, h + 1, height);
	}
}

int findBottomLeftValue_method2(TreeNode* root) {
	int height = depth(root);  // 求二叉树高度
	int res = root->val;
	dfs(root, res, 1, height);
	
	return res; 
}

int main() {
	// 手动创建二叉树
	auto root = new TreeNode(5);
	auto n1 = new TreeNode(4);
	auto n2 = new TreeNode(7);
	auto n3 = new TreeNode(12);
	auto n4 = new TreeNode(1);
	auto n5 = new TreeNode(10);
	root->left = n1;
	root->right = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	// 计算左下角的值
	int val = findBottomLeftValue_method2(root);
	cout << val << endl;

	return 0;
}