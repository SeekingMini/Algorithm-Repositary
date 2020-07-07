/*
 * 题目：二叉树的右视图
 * 链接：https://leetcode-cn.com/problems/binary-tree-right-side-view/
 */

#include <vector>
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

// 解法1：层序遍历
// 在遍历每一层时，判断该结点是否为当前层的最后一个结点。
vector<int> rightSideView_method1(TreeNode *root) {
    vector<int> nodes;
    if (!root)
        return nodes;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int currentSize = q.size();
        for (int i = 0; i < currentSize; i++) {
            TreeNode *p = q.front();
            q.pop();
            
            // 遍历到当前层的最后一个结点，即最右结点
            if (i == currentSize - 1)
                nodes.push_back(p->val);
                
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }

    return nodes;
}

// 解法2：深度优先遍历
// 对前序遍历进行改造，顺序变为【中->右->左】，因此访问到的第一个结点即为当前层的最右结点。
void dfs(TreeNode* root, vector<int> &nums, int depth) {
    if (!root)
        return;
    
    if (depth == nums.size())
        nums.push_back(root->val);
        
    dfs(root->right, nums, depth + 1);
    dfs(root->left, nums, depth + 1);
}

vector<int> rightSideView_method2(TreeNode *root) {
    vector<int> nums;
    dfs(root, nums, 0);
    
    return nums;
}


int main() {
    // 手动创建二叉树
    auto root = new TreeNode(1);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(5);
    auto n4 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    n1->right = n3;
    n2->right = n4;

    // 寻找二叉树右视图
    auto nodes = rightSideView_method2(root);
    for (int node: nodes)
        cout << node << " ";
    cout << endl;

    return 0;
}