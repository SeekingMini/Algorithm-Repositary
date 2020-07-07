/*
 * 题目：岛屿的周长
 * 链接：https://leetcode-cn.com/problems/island-perimeter/
 */

#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int dfs(vector<vector<int>> &grid, int r, int c) {
	// 从陆地走到边界
	if (!(r >= 0 && r <= grid.size() - 1 && c >= 0 && c <= grid[0].size() - 1)) return 1;
	// 从陆地走到岛屿
	if (grid[r][c] == 0) return 1;
	// 走到已经遍历过的岛屿
	if (grid[r][c] != 1) return 0;
	
	// 走到过的岛屿标记为2
	grid[r][c] = 2;
	
	return dfs(grid, r - 1, c) + 
	       dfs(grid, r, c - 1) + 
		   dfs(grid, r + 1, c) +
		   dfs(grid, r, c + 1);
}

int islandPerimeter(vector<vector<int>>& grid) {
	// 网格的行数与列数
	const int row = grid.size();
	const int col = grid[0].size();
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == 1)
				return dfs(grid, i, j);
		}
	}
	return 0;
}

int main() {
	int row, col, n;
	
	// 输入数据
	scanf("%d %d\n", &row, &col);
	vector<vector<int>> grid(row, vector<int>(col, 0));
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			cin >> n;
			grid[r][c] = n;
		}
	}
	
	// 计算岛屿周长
	int val = islandPerimeter(grid);
	printf("%d\n", val);
	
	return 0;
}