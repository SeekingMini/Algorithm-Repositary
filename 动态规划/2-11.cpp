/*
 * 题目：不同路径 II
 * 链接：https://leetcode-cn.com/problems/unique-paths-ii/
 */

#include <vector>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    // dp[i][j]表示从(0, 0)开始到达(i, j)的路径数
    int row = obstacleGrid.size();    // 行数
    int col = obstacleGrid[0].size(); // 列数
    vector<vector<long int>> dp(row, vector<long int>(col, 0));

    // 初始化dp
    int i, j;
    for (j = 0; j < col; j++)
    {
        if (obstacleGrid[0][j] == 1) // 遇到障碍物
            break;
        else
            dp[0][j] = 1;
    }
    for (i = 0; i < row; i++)
    {
        if (obstacleGrid[i][0] == 1) // 遇到障碍物
            break;
        else
            dp[i][0] = 1;
    }

    // 动态规划
    for (i = 1; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            if (obstacleGrid[i][j] == 0) // 没有障碍物
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}

int main()
{
    int m, n;

    // 输入数据
    cin >> m >> n;
    vector<vector<int>> grid;
    int i, j;
    for (i = 0; i < m; i++)
    {
        vector<int> row;
        for (j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            row.push_back(t);
        }
        grid.push_back(row);
    }

    // 计算路径数
    long int path_num = uniquePathsWithObstacles(grid);
    printf("%ld\n", path_num);

    return 0;
}
