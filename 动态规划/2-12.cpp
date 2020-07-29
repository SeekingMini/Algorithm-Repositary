/* 
 * 题目：最长回文子串
 * 链接：https://leetcode-cn.com/problems/longest-palindromic-substring/
 */ 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 寻找最长回文串
string palidrome(string &s, int l, int r) {
	while (l >= 0 && r < s.size() && s[l] == s[r]) {
		// 向两边展开
		l--;
		r++;
	}
	
	return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
	string res;
	for (int i = 0; i < s.size(); i++) {
		string s1 = palidrome(s, i, i);
		string s2 = palidrome(s, i, i + 1);
		res = res.size() > s1.size() ? res : s1;
		res = res.size() > s2.size() ? res : s2;
	}
	
	return res;
}

int main() {
	string s;
	
	// 输入数据
	cin >> s;
	
	// 计算最长回文子串
	string res = longestPalindrome(s);
	cout << res << endl;
	
	return 0;
}