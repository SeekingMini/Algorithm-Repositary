/*
 * 题目：无重叠区间
 * 链接：https://leetcode-cn.com/problems/non-overlapping-intervals/
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> i1, vector<int> i2)
{
    return i1[1] < i2[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return 0;

    // 按照end从小到大排序
    sort(intervals.begin(), intervals.end(), cmp);
    int count = 1;
    int end = intervals[0][1];
    for (vector<int> interval : intervals)
    {
        int start = interval[0];
        if (start >= end)
        {
            count++;
            end = interval[1];
        }
    }
    return intervals.size() - count;
}

int main()
{
    int start, end;
    vector<vector<int>> intervals;
    // 输入区间
    while (cin >> start >> end)
    {
        vector<int> interval;
        interval.push_back(start);
        interval.push_back(end);
        intervals.push_back(interval);
        if (getchar() == '\n')
            break;
    }
    // 计算最小移除区间数量
    int ans = eraseOverlapIntervals(intervals);
    cout << ans << endl;

    return 0;
}