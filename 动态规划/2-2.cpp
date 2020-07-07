/*
 * 题目：三角形最小路径和
 * 链接：https://leetcode-cn.com/problems/triangle/
 */

#include <vector>
#include <iostream>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    if (triangle.size() == 0)
        return 0;

    int height = triangle.size(); // 三角形的高度
    // dp[h][i]表示
    vector<vector<int>> dp(height, vector<int>(height, 0));
    dp[0][0] = triangle[0][0];
    for (int h = 1; h < height; h++)
    {
        for (int i = 0; i < h + 1; i++)
        {
            if (i == 0)
            {
                dp[h][i] = triangle[h][i] + dp[h - 1][0];
            }
            else if (i == h)
            {
                dp[h][i] = triangle[h][i] + dp[h - 1][i - 1];
            }
            else
            {
                int nb1 = i - 1; // 第1个相邻点
                int nb2 = i;     // 第2个相邻点
                dp[h][i] = min(triangle[h][i] + dp[h - 1][nb1],
                               triangle[h][i] + dp[h - 1][nb2]);
            }
        }
    }
    int min_total = *min_element(dp[height - 1].begin(), dp[height - 1].end());
    return min_total;
}

int main()
{
    int h, n;
    vector<vector<int>> triangle;
    // 输入三角形
    cin >> h;
    for (int i = 0; i < h; i++)
    {
        vector<int> one_row;
        while (cin >> n)
        {
            one_row.push_back(n);
            if (getchar() == '\n')
                break;
        }
        triangle.push_back(one_row);
    }
    // 计算最小路径
    int min_total = minimumTotal(triangle);
    cout << min_total << endl;

    return 0;
}