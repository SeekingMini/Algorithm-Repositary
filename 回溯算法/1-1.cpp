/*
 * 题目：字母大小写全排列
 * 链接：https://leetcode-cn.com/problems/letter-case-permutation/
 */

#include <vector>
#include <iostream>

using namespace std;

bool isLetter(const char c) {
    if (c >= 'A' && c <= 'Z') return true;
    return c >= 'a' && c <= 'z';
}

void dfs(string &S, vector<string> &res, int start) {
    res.push_back(S);  // 添加组合

    for (int i = start; i < S.size(); i++) {
        // 遇到字母
        if (isLetter(S[i])) {
            // 判断字母大小写
            if (S[i] >= 'a' && S[i] <= 'z') {
                // 做选择
                S[i] -= 32;
                // 继续搜索
                dfs(S, res, i + 1);
                // 撤销选择
                S[i] += 32;
            } else {
                // 做选择
                S[i] += 32;
                // 继续搜索
                dfs(S, res, i + 1);
                // 撤销选择
                S[i] -= 32;
            }
        }
    }
}

vector<string> letterCasePermutation(string S) {
    vector<string> res;
    dfs(S, res, 0);

    return res;
}

int main() {
    string S;

    // 输入数据
    cin >> S;

    vector<string> res = letterCasePermutation(S);

    for (const string &str : res)
        cout << str << endl;

    return 0;
}