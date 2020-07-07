/*
 * 题目：不同路径
 * 链接：https://leetcode-cn.com/problems/unique-paths/
 */
#include <vector>
#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    // dp[i][j]表示从(0, 0)开始到达(i, j)的路径数
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化dp
    int i, j;
    for (j = 0; j < n; j++)
        dp[0][j] = 1;
    for (i = 0; i < m; i++)
        dp[i][0] = 1;

    // 动态规划
    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    return dp[m - 1][n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    // 计算路径数
    int path_num = uniquePaths(m, n);
    cout << path_num << endl;

    return 0;
}