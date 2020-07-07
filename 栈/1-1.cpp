/*
 * 题目：下一个更大元素 I
 * 链接：https://leetcode-cn.com/problems/next-greater-element-i/
 */

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

// 计算数组nums中的每一个元素的下一个更大元素
void nextGreaterElements(const vector<int> &nums, unordered_map<int, int> &hash) {
	stack<int> st;
	
	for (int i = nums.size() - 1; i >= 0; i--) {
		// 栈不为空且栈顶元素不大于nums[i]
		while (!st.empty() && st.top() <= nums[i]) st.pop();
		
		// 如果栈中没有比nums[i]更大的元素，则结果为-1
		hash[nums[i]] = st.empty() ? -1 : st.top();
		st.push(nums[i]);
	}
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	if (nums1.empty() || nums2.empty())
		return ans;
		
	unordered_map<int, int> hash;
	nextGreaterElements(nums2, hash);
	
	for(int num: nums1)
		ans.push_back(hash[num]);
	
	return ans;
}

int main()
{
	int n;
	vector<int> nums1, nums2;

	// 输入数据
	while (cin >> n) {
		nums1.push_back(n);

		if (getchar() == '\n')
			break;
	}
	while (cin >> n) {
		nums2.push_back(n);

		if (getchar() == '\n')
			break;
	}

	// 计算
	vector<int> ans = nextGreaterElement(nums1, nums2);
	for(int n: ans)
		cout << n << " ";
	cout << endl;

	return 0;
}