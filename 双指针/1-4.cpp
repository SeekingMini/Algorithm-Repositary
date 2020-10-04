/*
 * 题目：移动零
 * 链接：https://leetcode-cn.com/problems/move-zeroes/
 */

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
	// 双指针
	int slow = 0, fast = 0;

	while (fast < nums.size()) {
		// nums[fast]不等于指定元素
		if (nums[fast] != val) {
			// 把不等于val的元素换到前面
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}

	return slow;
}

void moveZeroes(vector<int> &nums) {
	// 删除数组中所有的0
	int l = removeElement(nums, 0);

	while (l < nums.size()) {
		nums[l] = 0;
		l++;
	}
}

int main() {
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 移动零
	moveZeroes(nums);
	for (int num : nums)
		cout << num << " ";
	cout << endl;

	return 0;
}