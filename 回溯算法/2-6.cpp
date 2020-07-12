/*
 * 题目：组合总和 II
 * 链接：https://leetcode-cn.com/problems/combination-sum-ii/
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(const vector<int> &candidates, vector<vector<int>> &res, vector<int> &track, int rest, int start) {
	// 搜索完毕并回溯
	if (rest == 0) {
		if (find(res.begin(), res.end(), track) == res.end()) res.push_back(track);
		return;
	}
	
	for (int i = start; i < candidates.size() && rest - candidates[i] >= 0 ; i++) {
		// 做选择
		track.push_back(candidates[i]);
		// 继续搜索
		dfs(candidates, res, track, rest - candidates[i], i + 1);
		// 撤销选择
		track.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> track;
	dfs(candidates, res, track, target, 0);
	
	return res;
}

int main() {
	int target, n;
	vector<int> candidates;
	
	// 输入数据
	cin >> target;
	while (cin >> n) {
		candidates.push_back(n);
		
		if (getchar() == '\n') break;
	}
	
	// 计算所有组合
	vector<vector<int>> res = combinationSum2(candidates, target);
	
	for (vector<int> nums : res) {
		for (int num : nums)
			cout << num << " ";
		cout << endl;
	}
	
	return 0;
}