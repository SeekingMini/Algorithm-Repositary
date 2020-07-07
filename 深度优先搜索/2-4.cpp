/*
 * 题目：水域大小
 * 链接：https://leetcode-cn.com/problems/pond-sizes-lcci/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>> &land, const int r, const int c) {
	// 越过边界
	if (r == -1 || r == land.size() || c == -1 || c == land[0].size()) return 0;
	// 碰到非水域
	if (land[r][c] != 0) return 0;

	land[r][c] = 1;  // “染色”为非水域

	// 继续向四个方向搜索
	return 1 
	       + dfs(land, r + 1, c) + dfs(land, r - 1, c) + dfs(land, r, c + 1) + dfs(land, r, c - 1)
		   + dfs(land, r + 1, c + 1) + dfs(land, r - 1, c - 1) + dfs(land, r - 1, c + 1) + dfs(land, r + 1, c - 1);
}

vector<int> pondSizes(vector<vector<int>> &land) {
	int row = land.size();     // 行数
	int col = land[0].size();  // 列数

	vector<vector<int>> visited(row, vector<int>(col, 0));
	vector<int> ponds;

	// 深度优先搜索
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			// 碰到水池
			int size = dfs(land, r, c);
			if (size != 0) ponds.push_back(size);
		}
	}
	sort(ponds.begin(), ponds.end());

	return ponds;
}

int main() {
	int row, col, n;

	// 输入数据
	cin >> row >> col;
	vector<vector<int>> land(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> n;
			land[i][j] = n;
		}
	}

	// 计算水域大小
	vector<int> ponds = pondSizes(land);
	for (int pond: ponds) cout << pond << " ";
	cout << endl;

	return 0;
}