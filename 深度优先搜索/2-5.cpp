/*
 * 题目：岛屿的最大面积
 * 链接：https://leetcode-cn.com/problems/max-area-of-island/
 */

#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<vector<int>> &grid, int r, int c) {
	// 越界
	if (r == -1 || r == grid.size() || c == -1 || c == grid[0].size()) return 0;
	// 碰到海洋
	if (grid[r][c] == 0) return 0;
	
	grid[r][c] = 0;  // 把岛屿“染色”成海洋
	
	// 在四个方向上继续搜索
	return 1 + dfs(grid, r + 1, c)
			 + dfs(grid, r - 1, c)
	         + dfs(grid, r, c + 1)
	         + dfs(grid, r, c - 1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	const int row = grid.size();     // 行数
	const int col = grid[0].size();  // 列数
	
	int maxSize = 0; 
	
	// 深度优先搜索
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			// 碰到岛屿
			if (grid[r][c] == 1) {
				int size = dfs(grid, r, c);
				maxSize = max(maxSize, size);
			}
		}
	}
	
	return maxSize;
}

int main() {
	int row, col;
	int n;
	
	// 输入数据
	cin >> row >> col;
	vector<vector<int>> grid(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> n;
			grid[i][j] = n;
		}
	}
	
	// 计算最大的岛屿面积
	int size = maxAreaOfIsland(grid);
	cout << size << endl;
	
	return 0;
}