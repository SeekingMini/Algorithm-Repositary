/*
 * 题目：组合总和 III
 * 链接：https://leetcode-cn.com/problems/combination-sum-iii/
 */

#include <vector>
#include <iostream>

using namespace std;

void dfs(const vector<int> &candidates, vector<vector<int>> &res, vector<int> &track, const int k, const int target,
         int start) {
    // 搜索完毕并回溯
    if (target == 0 && track.size() == k) {
        res.push_back(track);
        return;
    }

    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
        int num = candidates[i];
        // 做选择
        track.push_back(num);
        // 继续搜索
        dfs(candidates, res, track, k, target - num, i + 1);
        // 撤销选择
        track.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> track;
    vector<vector<int>> res;
    if (k <= 0 || n <= 0) return res;
    dfs(candidates, res, track, k, n, 0);

    return res;
}

int main() {
    int n, k;

    // 输入数据
    cin >> k >> n;

    // 计算所有排列组合
    vector<vector<int>> res = combinationSum3(k, n);

    for (const vector<int> &nums : res) {
        for (int num : nums)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}