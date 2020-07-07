/*
 * 题目：最大子序和
 * 链接：https://leetcode-cn.com/problems/maximum-subarray/
 */

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums) {
    int res = 0;
    if (nums.empty())
        return res;
    if (nums.size() == 1)
        return nums[0];

    // dp[i]表示nums[1...i]的最大子序和
    int l = nums.size();
    vector<int> dp(l + 1, 0);
    dp[1] = nums[0];

    // 动态规划
    for (int i = 1; i < l; i++) {
        if (dp[i] < 0)
            dp[i + 1] = nums[i];
        else
            dp[i + 1] = dp[i] + nums[i];
        res = max(res, dp[i + 1]);
    }

    return res;
}

int main() {
    int n;
    vector<int> nums;

    // 输入数据
    while (cin >> n) {
        nums.push_back(n);

        if (getchar() == '\n')
            break;
    }

    // 计算最大子序和
    int res = maxSubArray(nums);
    cout << res << endl;

    return 0;
}