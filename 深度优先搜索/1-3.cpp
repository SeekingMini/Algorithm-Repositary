/*
 * 题目：颜色填充
 * 链接：https://leetcode-cn.com/problems/color-fill-lcci/
 */

#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>> &image, int r, int c, int oldColor, int newColor) {
	// 越界
	if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) return;
	
	const int color = image[r][c];
	if (color != newColor && color == oldColor) {
		image[r][c] = newColor;  // 染成新颜色（使其已经搜索过）
		dfs(image, r + 1, c, oldColor, newColor);
		dfs(image, r, c + 1, oldColor, newColor);
		dfs(image, r - 1, c, oldColor, newColor);
		dfs(image, r, c - 1, oldColor, newColor);
	}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {	
	const int oldColor = image[sr][sc];  // 初始坐标点原来的颜色
	dfs(image, sr, sc, oldColor, newColor);

	return image;
}

// 二维数组
int main() {
	int row, col, n;
	int sr, sc, newColor;
	
	// 输入数据
	cin >> row >> col;
	cin >> sr >> sc >> newColor;
	vector<vector<int>> image(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> n;
			image[i][j] = n;
		}
	}
	
	// 返回填充后的数组
	floodFill(image, sr, sc, newColor);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << image[i][j] << " ";	
		}
		cout << endl;
	}
	
	return 0;
}