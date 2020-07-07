/*
 * 题目：最长上升子序列
 * 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

#include <vector>
#include <iostream>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;

    // dp[i]表示子数组numns[1...i]的最长上升子序列
    vector<int> dp(nums.size(), 1);
    int max_length = 0;
    
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                max_length = max(max_length, dp[i]);
            }
        }
    }
    return max_length;
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

    // 计算最小花费
    cout << lengthOfLIS(nums) << endl;

    return 0;
}