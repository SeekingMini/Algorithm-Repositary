/*
 * 题目：子集 II
 * 链接：https://leetcode-cn.com/problems/subsets-ii/
 */ 

#include <vector>
#include <iostream>

using namespace std;

void dfs(const vector<int> &nums, vector<vector<int>> &subSets, vector<int> &subSet, int start) {
	// 添加不重复的子集
	if (find(subSets.begin(), subSets.end(), subSet) == subSets.end())
		subSets.push_back(subSet);

	for (int i = start; i < nums.size(); i++) {
		// 做选择
		subSet.push_back(nums[i]);
		// 继续搜索
		dfs(nums, subSets, subSet, i + 1);
		// 回溯并撤销选择
		subSet.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
	vector<int> subSet;
	vector<vector<int>> subSets;
	sort(nums.begin(), nums.end());
	dfs(nums, subSets, subSet, 0);

	return subSets;
}

int main() {
	vector<int> nums;
	int n;
	
	// 输入数据
	while (cin >> n) {
		nums.push_back(n);
		
		if (getchar() == '\n') break;
	}
	
	// 计算所有子集
	vector<vector<int>> subSets = subsetsWithDup(nums);
	for (vector<int> set: subSets) {
		for (int num: set)
			cout << num << " ";
		cout << endl;
	}
	
	return 0;
}