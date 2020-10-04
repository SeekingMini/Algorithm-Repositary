/*
 * 题目：移除元素
 * 链接：https://leetcode-cn.com/problems/remove-element/
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

int main() {
	int n, val;
	vector<int> nums;

	// 输入数据
	cin >> val;
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 移除指定元素
	int len = removeElement(nums, val);
	cout << len << endl;

	return 0;
}