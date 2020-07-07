/*
 * 题目：被围绕的区域
 * 链接：https://leetcode-cn.com/problems/surrounded-regions/
 */

#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<char>> &board, int r, int c) {
	// 越界
	if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
	// 碰到*说明已经搜索过，碰到X略过
	if (board[r][c] == '*' || board[r][c] == 'X') return;
	
	// 碰到O
	board[r][c] = '*';
	dfs(board, r + 1, c);
	dfs(board, r - 1, c);
	dfs(board, r, c + 1);
	dfs(board, r, c - 1);
}

void solve(vector<vector<char>>& board) {
	if (board.size() == 0) return;
	const int row = board.size();
	const int col = board[0].size();
	
	// 深度优先搜索
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// 判断是否在边界
			bool isAtEdge = (i == 0 || i == row - 1 || j == 0 || j == col - 1);
			// 从边界开始并进行填充
			if (isAtEdge && board[i][j] == 'O') dfs(board, i, j);
		}
	}
	
	// 填充
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// 不在边界，需要填充
			if (board[i][j] == 'O') board[i][j] = 'X';
			// 在边界且被搜索过，所以要变回O
			if (board[i][j] == '*') board[i][j] = 'O';
		}
	}
}

int main() {
	int row, col;
	char c;
	
	// 输入数据
	cin >> row >> col;
	vector<vector<char>> board(row, vector<char>(col, 0));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> c;
			board[i][j] = c;
		}
	}
	
	// 填充
	solve(board);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}