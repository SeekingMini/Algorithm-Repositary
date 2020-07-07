/*
 * 题目：飞地的数量
 * 链接：https://leetcode-cn.com/problems/number-of-enclaves/
 */

#include <iostream>
#include <vector>

using namespace std;

// 使用深度优先计算可以逃脱边界的陆地数量
void dfs(const vector<vector<int>>& A, vector<vector<int>>& visited, int& count, int r, int c)
{
    // 越过边界
    if (r < 0 || r == A.size() || c < 0 || c == A[0].size() || A[r][c] == 0) return;
    // 碰到已访问过的地方
    if (visited[r][c] == 1) return;

    count++;
    visited[r][c] = 1; // 标记为已访问

    // 四个方向继续搜索
    dfs(A, visited, count, r + 1, c);
    dfs(A, visited, count, r - 1, c);
    dfs(A, visited, count, r, c + 1);
    dfs(A, visited, count, r, c - 1);
}

int numEnclaves(vector<vector<int>>& A)
{
    int row = A.size();    // 行数
    int col = A[0].size(); // 列数

    vector<vector<int>> visited(row, vector<int>(col, 0));
    int numberOfOnes = 0; // 陆地的数量
    int count = 0;        // 可以到边界的陆地数量

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            // 遇到陆地
            if (A[r][c] == 1) {
                numberOfOnes++;
                // 陆地没有被访问过且在边界上
                if (visited[r][c] == 0 && (r == 0 || r == row - 1 || c == 0 || c == col - 1)) 
                    dfs(A, visited, count, r, c);
            }
        }
    }

    return numberOfOnes - count;
}

int main()
{
    int row, col, n;

    // 输入数据
    cin >> row >> col;
    vector<vector<int>> A(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> n;
            A[i][j] = n;
        }
    }

    // 计算无法离开边界的陆地数量
    int count = numEnclaves(A);
    cout << count << endl;

    return 0;
}