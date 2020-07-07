/*
 * 题目：两数之和
 * 链接：https://leetcode-cn.com/problems/two-sum/
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	// key为数组元素，value为对应下标
	unordered_map<int, int> hash;
	
	// 初始化hash
	const int size = nums.size();
	for (int i = 0; i < size; i++) {
		hash[nums[i]] = i;
	}
	
	// 计算下标
	vector<int> ans;
	for (int i = 0; i < size; ++i) {
		const int num = nums[i];
		if (hash[target - num] != 0 && i != hash[target - num]) 
			return {i, hash[target - num]};
	}
	return ans;
}

int main() {
	int n, target;
	vector<int> nums;

	// 输入数据
	cin >> target;
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}
	
	// 计算下标
	vector<int> index = twoSum(nums, target);
	cout << index[0] << " " << index[1] << endl;

	return 0;
}