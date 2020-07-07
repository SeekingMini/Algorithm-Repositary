/*
 * 题目：按摩师
 * 链接：https://leetcode-cn.com/problems/the-masseuse-lcci/
 */

#include <iostream>
#include <vector>

using namespace std;

int massage(vector<int>& nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];

    // dp[i]表示nums[1...i]的预约的总时长
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    int max_time = 0;
    
    for (int i = 2; i <= nums.size(); i++) {
        dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        max_time = max(dp[i], max_time);
    }
    return max_time;
}

int main()
{
    vector<int> nums;
    int n;

    // 输入数据
    while (cin >> n) {
        nums.push_back(n);
        if (getchar() == '\n')
            break;
    }

    // 计算最长预约时间
    int max_time = massage(nums);
    cout << max_time << endl;

    return 0;
}