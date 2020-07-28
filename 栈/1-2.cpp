/*
 * 题目：有效的括号
 * 链接：https://leetcode-cn.com/problems/valid-parentheses/
 */

#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s) {
	map<char, char> m;
	m['('] = ')';
	m[')'] = '(';
	m['['] = ']';
	m[']'] = '[';
	m['{'] = '}';
	m['}'] = '{';
	
	// 遍历字符串进行匹配
	stack<char> st;
	int i = 0;
	while (i < s.size()) {
		char c = s[i];
		
		// 碰到做括号入栈
		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
			i++;
			continue;
		}
		// 碰到右括号进行匹配
		else {
			// 栈为空
			if (st.empty()) return false;
			// 无法匹配
			char top = st.top();
			if (top != m[c]) return false;
			else {
				st.pop();
				i++;
				continue;
			}
		}
	}
	
	if (st.empty()) return true;
	else return false;
}

int main() {
	string s;
	
	// 输入数据
	cin >> s;
	
	// 判断是否有效
	bool valid = isValid(s);
	cout << valid << endl;
	
	return 0;
}