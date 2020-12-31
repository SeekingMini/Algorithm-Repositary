/*
 * 题目：合并区间
 * 链接：https://leetcode-cn.com/problems/merge-intervals/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int>& b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return intervals;

    // 按照区间起点排序
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        // 当前区间
        vector<int> current = intervals[i];

        // 结果集最后一个区间
        vector<int> last = res[res.size() - 1];
        if (current[0] <= last[1]) {
            last[1] = max(last[1], current[1]);
            res.pop_back();
            res.push_back(last);
        } else {
            res.push_back(current);
        }
    }

    return res;
}   

int main() {
    // input
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {1, 3}, {3, 7}};
    
    // output
    vector<vector<int>> res =merge(intervals);
    for (vector<int> interval : res) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    
    return 0;
}