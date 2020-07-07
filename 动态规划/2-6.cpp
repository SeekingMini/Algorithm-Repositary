/*
 * 题目：礼物的最大价值
 * 链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */

#include <vector>
#include <cstdio>

using namespace std;

int maxValue(vector<vector<int> > &grid) {
	const int row = grid.size();  // 行数
	const int col = grid[0].size();  // 列数

	// dp[i][j]表示从左上角grid[0][0]到grid[i-1][j-1]的最大价值
	vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
	// 初始化
	for (int i = 1; i <= row; i++)
		dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
	for (int j = 1; j <= col; j++)
		dp[1][j] = dp[1][j - 1] + grid[0][j - 1];

	// 动态规划
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
	}

	return dp[row][col];
}

int main() {
	int row, col, n;
	vector<vector<int>> grid;

	// 输入数据
	scanf("%d %d\n", &row, &col);
	for (int i = 0; i < row; i++) {
		vector<int> oneRow;
		for (int j = 0; j < col; j++) {
			scanf("%d", &n);
			oneRow.push_back(n);
		}
		grid.push_back(oneRow);
	}

	// 计算最大价值
	int val = maxValue(grid);
	printf("%d\n", val);

	return 0;
}