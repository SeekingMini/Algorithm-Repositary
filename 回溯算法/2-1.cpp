/*
 * 题目：全排列
 * 链接：https://leetcode-cn.com/problems/permutations/
 */

#include <vector>
#include <iostream>

using namespace std;

void dfs(const vector<int> &nums, vector<vector<int>> &permutations, vector<int> &permutation) {
	// 搜索完毕并回溯
	if (permutation.size() == nums.size()) {
		permutations.push_back(permutation);
		return;
	}

	for (int num : nums) {
		if (find(permutation.begin(), permutation.end(), num) != permutation.end()) continue;
		// 做选择
		permutation.push_back(num);
		// 深度优先搜索
		dfs(nums, permutations, permutation);
		// 撤销选择
		permutation.pop_back();
	}
}

vector<vector<int>> permute(vector<int> &nums) {
	vector<vector<int>> permutations;
	vector<int> permutation;
	dfs(nums, permutations, permutation);

	return permutations;
}

int main() {
	vector<int> nums;
	int n;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 计算全排列
	vector<vector<int>> permutations = permute(nums);
	for (const vector<int> &permutation: permutations) {
		for (int num : permutation)
			cout << num << " ";
		cout << endl;
	}

	return 0;
}