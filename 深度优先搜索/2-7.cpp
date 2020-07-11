/*
 * 题目：目标和
 * 链接：https://leetcode-cn.com/problems/target-sum/
 */

#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<int>& nums, int i, int rest, int& way) {
	// 遍历完数组且余值为0
	if (i == nums.size()) {
		if (rest == 0) way++;
		return;
	}
	
	// 给nums[i]选择-号
	rest += nums[i];
	// 继续搜索
	dfs(nums, i + 1, rest, way);
	// 撤销选择
	rest -= nums[i];
	
	// 给nums[i]选择+号
	rest -= nums[i];
	// 继续搜索
	dfs(nums, i + 1, rest, way);
	// 撤销选择
	rest += nums[i];
}

int findTargetSumWays(vector<int>& nums, int S) {
	int way = 0;
	dfs(nums, 0, S, way);
	
	return way;
}

int main() {
	vector<int> nums;
	int S, n;
	
	// 输入数据
	cin >> S;
	while (cin >> n) {
		nums.push_back(n);
		
		if (getchar() == '\n') break;
	}
	
	// 计算方法数
	int way = findTargetSumWays(nums, S);
	cout << way << endl;
	
	return 0;
}