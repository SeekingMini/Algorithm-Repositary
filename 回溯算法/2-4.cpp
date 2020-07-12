/*
 * 题目：括号生成
 * 链接：https://leetcode-cn.com/problems/generate-parentheses/
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// 检查括号合法性
bool isValid(const string &s) {
	int left = 0, right = 0;  // 左右括号数量
	for (char c : s) {
		if (c == '(') left++;
		else right++;

		if (right > left) return false;
	}

	return left == right;
}

void dfs(vector<string> &res, string &track, int n, int i) {
	const int len = 2 * n;
	// 搜索完毕并回溯
	if (i == len) {
		// 检查是否为合法组合
		if (track.length() == len && isValid(track)) res.push_back(track);
		return;
	}

	// 添加左括号
	track.push_back('(');
	// 继续搜索
	dfs(res, track, n, i + 1);
	// 撤销选择
	track.pop_back();

	// 添加右括号
	track.push_back(')');
	// 继续搜索
	dfs(res, track, n, i + 1);
	// 撤销选择
	track.pop_back();
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	if (n == 0) return res;
	string track;
	dfs(res, track, n, 0);

	return res;
}

int main() {
	int n;

	// 输入数据
	cin >> n;

	// 生成所有括号
	vector<string> res = generateParenthesis(n);

	for (const string &s : res)
		cout << s << endl;
	cout << endl;

	return 0;
}