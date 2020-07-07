/*
 * 题目：分发饼干
 * 链接：https://leetcode-cn.com/problems/assign-cookies/
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    if (g.size() <= 0 || s.size() <= 0)
        return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;
    vector<int>::iterator itr_g;
    vector<int>::iterator itr_s;
    for (itr_s = s.begin(); itr_s != s.end(); itr_s++)
    {
        if (itr_g == g.end())
            break;
        if (*itr_s >= *itr_g) // 可以满足
        {
            count++;
            itr_g++;
        }
    }
    return count;
}

int main()
{
    vector<int> g, s;
    int n;
    // 输入胃口值
    while (cin >> n)
    {
        g.push_back(n);
        if (getchar() == '\n')
            break;
    }
    // 输入饼干尺寸
    while (cin >> n)
    {
        s.push_back(n);
        if (getchar() == '\n')
            break;
    }
    // 计算
    int count = findContentChildren(g, s);
    cout << count << endl;

    return 0;
}