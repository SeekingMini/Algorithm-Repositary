/*
 * 题目：组合
 * 链接：https://leetcode-cn.com/problems/combinations/
 */ 

#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& track, int n, int k, int start) {
	// 搜索完毕并回溯
	if (track.size() == k) {
		res.push_back(track);
		return;
	}
	
	for (int i = start; i <= n; i++) {
		// 做选择
		track.push_back(i);
		// 继续搜索
		dfs(res, track, n, k, i + 1);
		// 撤销选择
		track.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> res;
	if (n <= 0 || k <= 0) return res;
	vector<int> track;
	dfs(res, track, n, k, 1);
	
	return res;
}
	
int main() {
	int n, k;
	
	// 输入数据
	cin >> n >> k;
	
	// 计算所有组合
	vector<vector<int>> combinations = combine(n, k);
	
	for (vector<int> combination: combinations) {
		for (int num: combination)
			cout << num << " ";
		cout << endl;
	}
	
	return 0;
}