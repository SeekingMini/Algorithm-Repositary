/*
 * 题目：打家劫舍
 * 链接：https://leetcode-cn.com/problems/house-robber/
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    int l = nums.size();
    if (l == 0)
        return 0;
    if (l == 1)
        return nums[0];
    if (l == 2)
        return max(nums[0], nums[1]);

    int res = -1;
    // dp[i]表示子数组nums[1...i]可以获取的最大金额
    vector<int> dp(l + 1, 0);
    dp[1] = nums[0];
    dp[2] = max(nums[0], nums[1]);

    for (int i = 2; i < l; i++) {
        dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        res = max(res, dp[i + 1]);
    }
    return res;
}

int main()
{
    int n;
    vector<int> nums;

    // 输入数据
    while (cin >> n) {
        nums.push_back(n);

        if (getchar() == '\n')
            break;
    }

    // 计算最高金额
    int money = rob(nums);
    cout << money << endl;

    return 0;
}