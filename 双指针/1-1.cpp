/*
 * 题目：删除排序数组中的重复项
 * 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int len = nums.size();
	if (len == 0 || len == 1) return len;
	
	// 快慢指针
	int slow = 0, fast = 1;
	while (fast < len) {
		// 把重复元素换到数组最后
		if (nums[fast] != nums[slow]) {
			slow++;
			nums[slow] = nums[fast];
		}
		fast++;
	}
	return slow + 1;
}

int main() {
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}
	
	// 删除重复项
	int len = removeDuplicates(nums);
	for (int i = 0; i < len; i++) 
		cout << nums[i] << " ";
	cout << endl;

	return 0;
}