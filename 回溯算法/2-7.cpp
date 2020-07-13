/*
 * 题目：无重复字符串的排列组合
 * 链接：https://leetcode-cn.com/problems/permutation-i-lcci/
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void dfs(const string &S, vector<string> &res, string &track) {
    // 搜索完毕并回溯
    if (track.size() == S.size()) {
        res.push_back(track);
        return;
    }

    for (char c : S) {
        if (find(track.begin(), track.end(), c) != track.end()) continue;
        // 做选择
        track.push_back(c);
        // 继续搜索
        dfs(S, res, track);
        // 撤销选择
        track.pop_back();
    }
}

vector<string> permutation(string S) {
    string track;
    vector<string> res;
    dfs(S, res, track);

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