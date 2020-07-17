/*
 * 题目：活字印刷
 * 链接：https://leetcode-cn.com/problems/letter-tile-possibilities/
 */ 

#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void dfs(const string &S, vector<string> &res, string &track, vector<int> &isVisited, set<string> &s) {
	// 添加不重复的组合
	s.insert(track);
	
	for (int i = 0; i < S.size(); i++) {
		// 字符没有被使用过
		if (isVisited[i] == 0) {
			// 做选择
			track.push_back(S[i]);
			isVisited[i] = 1;  // 标记为使用过
			// 继续搜索
			dfs(S, res, track, isVisited, s);
			// 撤销选择
			track.pop_back();
			isVisited[i] = 0;  // 复原为未使用
		}
	}
}

int numTilePossibilities(string S) {
	string track;
	vector<string> res;
	set<string> s;
	vector<int> isVisited(S.size(), 0);
	dfs(S, res, track, isVisited, s);
	
	return s.size() - 1;
}

int main() {
	string S;
	
	// 输入数据
	cin >> S;
	
	// 计算序列数目
	int count = numTilePossibilities(S);
	cout << count << endl;
		
	return 0;
}