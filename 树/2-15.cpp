/*
 * 题目：祖父节点值为偶数的节点和
 * 链接：https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// 解法1：层序遍历
// 采用层序遍历的方法，在遍历每个结点时判断它的孙子结点
int sumEvenGrandparent_method1(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;

    // 层序遍历
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        TreeNode* child;

        // front结点值是偶数时为符合要求的祖父结点
        if (front->val % 2 == 0) {
            child = front->left;  // 左子结点
            if (child && child->left)
                sum += child->left->val;
            if (child && child->right)
                sum += child->right->val;

            child = front->right;  // 右子结点
            if (child && child->left)
                sum += child->left->val;
            if (child && child->right)
                sum += child->right->val;
        }

        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    return sum;
}

// 解法2：深度优先遍历
// 定义这样一个三元组(val_gp, val_p, node)，其中val_gp表示祖父结点值，val_p表示父结点值，node表示子结点。
// 通过深度优先遍历，不停更新三元组的状态进行结果的求解。
void dfs(TreeNode* node, int val_gp, int val_p, int &sum) {
    if (!node)
        return;
    
    // 判断祖父结点值
    if (val_gp % 2 == 0) sum += node->val;
    dfs(node->left, val_p, node->val, sum);
    dfs(node->right, val_p, node->val, sum);
}

int sumEvenGrandparent_method2(TreeNode* root) {
    int sum = 0;
    // 初始状态val_gp和val_p都设置为1
    dfs(root, 1, 1, sum);
    
    return sum;
}

int main()
{
    // 手动创建二叉树
    auto root = new TreeNode(6);
    auto n1 = new TreeNode(7);
    auto n2 = new TreeNode(8);
    auto n3 = new TreeNode(2);
    auto n4 = new TreeNode(7);
    auto n5 = new TreeNode(1);
    auto n6 = new TreeNode(3);
    auto n7 = new TreeNode(9);
    auto n8 = new TreeNode(1);
    auto n9 = new TreeNode(4);
    auto n10 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n3->left = n7;
    n4->left = n8;
    n4->right = n9;
    n5->right = n10;

    // 创建特定深度链表
    int sum = sumEvenGrandparent_method2(root);
    cout << sum << endl;

    return 0;
}