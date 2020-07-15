/*
 * 题目：有重复字符串的排列组合
 * 链接：https://leetcode-cn.com/problems/permutation-ii-lcci/
 */ 

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void dfs(const string &S, vector<string> &res, string &track, vector<int> &isVisited) {
	// 添加组合并回溯
	if (track.size() == S.size()) {
		// 去除重复组合
		if (find(res.begin(), res.end(), track) == res.end()) res.push_back(track);
		return;
	}
	
	for (int i = 0; i < S.size(); i++) {
		// 该字符没有被使用过
		if (isVisited[i] == 0) {
			// 做选择
			track.push_back(S[i]);
			isVisited[i] = 1;
			// 继续搜索
			dfs(S, res, track, isVisited);
			// 撤销选择
			track.pop_back();
			isVisited[i] = 0;
		}
	}
}

vector<string> permutation(string S) {
	string track;
	vector<string> res;
	sort(S.begin(), S.end());
	vector<int> isVisited(S.size(), 0);
	dfs(S, res, track, isVisited);
	
	return res;
}

int main() {
	string S;
	
	// 输入数据
	cin >> S;
	
	// 计算所有排列组合
	vector<string> res = permutation(S);
	
	for (const string &str : res)
		cout << str << endl;
		
	return 0;
}