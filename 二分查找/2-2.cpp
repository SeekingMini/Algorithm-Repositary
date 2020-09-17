/*
 * 题目：寻找峰值
 * 链接：https://leetcode-cn.com/problems/find-peak-element/
 */

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	const int len = nums.size() - 1;
	int left = 0, right = len - 1;
	
	// 二分查找来寻找峰值
	while (left < right) {
		int mid = left + (right - left) / 2;
		
		if (nums[mid] > nums[mid + 1]) right = mid;
		else left = mid + 1;
	}
	
	return left;
}

int main() {
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}
	
	// 寻找峰值
	int res = findPeakElement(nums);
	cout << res << endl;

	return 0;
}
