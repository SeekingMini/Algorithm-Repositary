/*
 * 题目：将有序数组转换为二叉搜索树
 * 链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历
void traverse(TreeNode *root)
{
    if (root)
    {
        traverse(root->left);
        cout << root->val << " ";
        traverse(root->right);
    };
}

// 给定数组nums，把[low, high]内的元素转化为二叉搜索树，并返回根结点root
TreeNode *transform(vector<int> nums, int low, int high)
{
    if (low > high) return nullptr;

    int mid = low + (high - low) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    
    // root的左子树上构建二叉搜索树
    root->left = transform(nums, low, mid - 1);
    // root的右子树上构建二叉搜索树
    root->right = transform(nums, mid + 1, high);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int l = nums.size();
    return transform(nums, 0, l - 1);
}

int main()
{
    vector<int> nums;
    int n;

    // 输入数据
    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
            break;
    }

    TreeNode *root = sortedArrayToBST(nums);
    traverse(root); 
    cout << endl;

    return 0;
}