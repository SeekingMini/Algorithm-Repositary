/*
 * 题目：打家劫舍 I
 * 链接：https://leetcode-cn.com/problems/house-robber/
 */

#include <vector>
#include <iostream>

using namespace std;

int rob(vector<int>& nums)
{
	int l = nums.size();
	if (l == 0) return 0;
	if (l == 1) return nums[0];

	// dp[i]表示抢劫范围nums[1...i](i<=l)可以获取的最大金额
	vector<int> dp(l + 1, 0);
	dp[1] = nums[0];
	int res = -1;

	for (int i = 1; i < l; i++) {
		dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
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

		if (getchar() == '\n') break;
	}
	
	// 计算最大价值
	int val = rob(nums);
	cout << val << endl;

	return 0;
}