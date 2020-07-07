/*
 * 题目：用最少数量的箭引爆气球
 * 链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> i1, vector<int> i2)
{
    return i1[1] < i2[1];
}

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() == 0)
        return 0;
    // 按照每个气球的结束坐标从小到大排序
    sort(points.begin(), points.end(), cmp);
    int num_arrow = 1;            
    int arrow_end_point = points[0][0]; // 第一个气球的结束坐标
    for (vector<int> point : points)
    {
        int start = point[0]; // 气球的开始坐标
        if (arrow_end_point < start)
        {
            arrow_end_point = point[1];
            num_arrow++;
        }
    }
    return num_arrow;
}

int main()
{
    int start, end;
    vector<vector<int>> points;
    // 输入区间
    while (cin >> start >> end)
    {
        vector<int> interval;
        interval.push_back(start);
        interval.push_back(end);
        points.push_back(interval);
        if (getchar() == '\n')
            break;
    }
    // 计算最小移除区间数量
    int ans = findMinArrowShots(points);
    cout << ans << endl;

    return 0;
}
