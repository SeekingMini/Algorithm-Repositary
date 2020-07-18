/* 
 * 题目：长度为 n 的开心字符串中字典序第 k 小的字符串
 * 链接：https://leetcode-cn.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const string &S, char previous, const int n, vector<string> &res, string &track) {
	// 添加开心字符串并回溯
	if (track.size() == n) {
		res.push_back(track);
		return;
	}
	
	for (char c : S) {
		if (c != previous) {
			// 做选择
			track.push_back(c);
			// 继续搜索
			char tmp = previous; 
			previous = c;
			dfs(S, previous, n, res, track);
			previous = tmp;
			// 撤销选择
			track.pop_back();
		}
	}
}

string getHappyString(int n, int k) {
	vector<string> res;
	string track;
	dfs("abc", '\0', n, res, track);
	sort(res.begin(), res.end());
	
	if (k > res.size()) return "";
	else return res[k - 1];
}

int main() {
	int n, k;
	
	// 输入数据
	cin >> n >> k;
	
	// 计算特定开心字符串
	string s = getHappyString(n, k);
	cout << s << endl;
	
	return 0;
}