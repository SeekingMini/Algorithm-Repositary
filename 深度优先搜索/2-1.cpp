/*
 * 题目：岛屿数量
 * 链接：https://leetcode-cn.com/problems/number-of-islands/
 */

#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c) {
	// 越界
	if (r < 0 || r == grid.size() || c < 0 || c == grid[0].size()) return;
	// 略过海洋
	if (grid[r][c] == '0') return;

	// 把陆地变成海洋（使其已经搜索过）
	grid[r][c] = '0';
	dfs(grid, r + 1, c);
	dfs(grid, r, c + 1);
	dfs(grid, r - 1, c);
	dfs(grid, r, c - 1);
}
int numIslands(vector<vector<char>>& grid) {
	int num = 0;
	
	// 深度优先搜索
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// 碰到陆地
			if (grid[i][j] == '1') {
				num++;
				dfs(grid, i, j);
			}
		}
	}
	
	return num;
}

int main() {
	int row, col;
	char c;
	
	// 输入数据
	cin >> row >> col;
	vector<vector<char>> grid(row, vector<char>(col, '0'));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> c;
			grid[i][j] = c;
		}
	}
	
	// 计算岛屿数量
	int num = numIslands(grid);
	cout << num << endl;
	
	return 0;
}