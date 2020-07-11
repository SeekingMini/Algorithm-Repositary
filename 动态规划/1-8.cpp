/*
 * 题目：使用最小花费爬楼梯
 * 链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 */

#include <vector>
#include <iostream>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int l = cost.size();
    if (l >= 3)
    {
        // dp[i]表示到达从第i个阶梯出发的最小花费，最后要求的是d[l+1]即到达顶层的最小花费。
        vector<int> dp(l + 1, 0);
        for (int i = 0; i < l; i++)
        {
            if (i == 0 || i == 1)
                dp[i] = cost[i];
            else
                dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return min(dp[l - 1], dp[l - 2]);
    }
    else
        return min(cost[0], cost[1]);
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
    cout << minCostClimbingStairs(nums) << endl;

    return 0;
}