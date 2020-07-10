/*
 * 题目：钥匙和房间
 * 链接：https://leetcode-cn.com/problems/keys-and-rooms/
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(const vector<vector<int>> &rooms, set<int> &visited, int i) {
	visited.insert(i);

	for (int j: rooms[i]) {
		// 如果房间j不在集合中就去访问
		if (!visited.count(j))
			dfs(rooms, visited, j);
	}
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
	set<int> visited;
	// 深度优先搜索
	dfs(rooms, visited, 0);

	// 是否所有房间都访问到
	return visited.size() == rooms.size();
}

int main() {
	int num, key;
	vector<vector<int>> rooms;

	// 输入数据
	cin >> num;
	for (int i = 0; i < num; ++i) {
		vector<int> room;
		while (cin >> key) {
			room.push_back(key);

			if (getchar() == '\n') break;
		}
		rooms.push_back(room);
	}

	// 判断是否能解锁所有房间
	bool flag = canVisitAllRooms(rooms);
	cout << flag << endl;

	return 0;
}