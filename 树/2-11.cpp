/*
 * 题目：两棵二叉搜索树中的所有元素
 * 链接：https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
 */

#include <iostream>
#include <vector>

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

// 中序遍历
void traverse(TreeNode* root, vector<int>& nums)
{
    if (root) {
        traverse(root->left, nums);
        nums.push_back(root->val);
        traverse(root->right, nums);
    }
}

// 分别对两颗树进行中序遍历并将元素添加进数组，最后合并有序数组即可。
vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    // 分别进行中序遍历
    vector<int> nums1;
    vector<int> nums2;
    traverse(root1, nums1);
    traverse(root2, nums2);

    // 合并有序数组
    vector<int> nums;
    int s1 = nums1.size();
    int s2 = nums2.size();
    int i = 0, j = 0;

    while (i < s1 && j < s2) {
        if (nums1[i] < nums2[j])
            nums.push_back(nums1[i++]);
        else
            nums.push_back(nums2[j++]);
    }
    if (i != s1) {
        for (int k = i; k < s1; k++)
            nums.push_back(nums1[k]);
    }
    if (j != s2) {
        for (int k = j; k < s2; k++)
            nums.push_back(nums2[k]);
    }
    return nums;
}

int main()
{
    // 手动创建二叉树
    auto root1 = new TreeNode(-10);
    auto n11 = new TreeNode(0);
    auto n12 = new TreeNode(10);
    root1->left = n11;
    root1->right = n12;

    auto root2 = new TreeNode(5);
    auto n21 = new TreeNode(1);
    auto n22 = new TreeNode(7);
    auto n23 = new TreeNode(0);
    auto n24 = new TreeNode(2);
    root2->left = n21;
    root2->right = n22;
    n21->left = n23;
    n21->right = n24;

    // 按升序添加元素进数组
    vector<int> nums = getAllElements(root1, root2);
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}