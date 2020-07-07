/*
 * 题目：买卖股票的最佳时机
 * 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */

#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.empty()) return 0;

	// dp[i][0]表示第i天时不持有股票获得的最大利润
	// dp[i][1]表示第i天时持有股票获得的最大利润
	vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
	// 初始化
	dp[0][0] = 0;
	dp[0][1] = -prices[0];

	// 动态规划
	for(int i = 1; i < prices.size(); i++) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
		dp[i][1] = max(dp[i-1][1], -prices[i]);
	}

	return dp[prices.size() - 1][0];
}

int main() {
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 计算最大利润
	int val = maxProfit(nums);
	cout << val << endl;

	return 0;
}