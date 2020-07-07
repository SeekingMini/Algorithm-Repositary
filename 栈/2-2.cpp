/*
 * 题目：下一个更大元素 II
 * 链接：https://leetcode-cn.com/problems/next-greater-element-ii/
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 计算循环数组nums中的每一个元素的下一个更大元素
vector<int> nextGreaterElements(vector<int> &nums) {
	vector<int> ans(nums.size());
	stack<int> st;
	
	const int size = nums.size();
	for (int i = 2 * size - 1; i >= 0; i--) {
		// 栈不为空且栈顶元素不大于nums[i % size]
		while (!st.empty() && st.top() <= nums[i % size]) st.pop();
		
		// 如果栈中没有比nums[i]更大的元素，则结果为-1
		ans[i % size]= st.empty() ? -1 : st.top();
		st.push(nums[i % size]);
	}
	return ans;
}

int main()
{
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n')
			break;
	}

	// 计算
	vector<int> ans = nextGreaterElements(nums);
	for(int n: ans)
		cout << n << " ";
	cout << endl;

	return 0;
}