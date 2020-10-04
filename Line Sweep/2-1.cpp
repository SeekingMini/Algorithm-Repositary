/*
 * 题目：删除被覆盖区间
 * 链接：https://leetcode-cn.com/problems/remove-covered-intervals/
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 自定义排序
bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int removeCoveredIntervals(vector<vector<int>> &intervals) {
    const int size = intervals.size();
    // 先排序
    sort(intervals.begin(), intervals.end(), cmp);

    int res = 0; // 被覆盖区间的个数
    int left = intervals[0][0];
    int right = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        vector<int> interval = intervals[i];

        // 1. 区间被覆盖
        if (left <= interval[0] && right >= interval[1])
            res++;
        // 2. 区间可以合并
        if (right >= interval[0] && right <= interval[1])
            right = interval[1];
        // 3. 不相交，更新起点和终点
        if (right < interval[0]) {
            left = interval[0];
            right = interval[1];
        }
    }

    return size - res;
}

int main() {
    // 输入数据
    int N, n;
    vector<vector<int>> intervals;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        vector<int> interval;
        while (cin >> n) {
            interval.push_back(n);
            if (getchar() == '\n')
                break;
        }
        intervals.push_back(interval);
    }

    // 计算
    int count = removeCoveredIntervals(intervals);
    cout << count << endl;

    return 0;
}