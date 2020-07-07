/*
 * 题目：员工的重要性
 * 链接：https://leetcode-cn.com/problems/employee-importance/
 */

#include <vector>
#include <iostream>

using namespace std;

class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
	
	// init
	Employee(int id, int importance, vector<int> subordinates) {
		this->id = id;
		this->importance = importance;
		this->subordinates = subordinates;
	}
	
	Employee() {
		this->id = 0;
		this->importance = 0;
		this->subordinates = vector<int>();
	}
};

void dfs(const vector<Employee*> employees, Employee* employee, vector<int> &visted, int &val, int id) {
	// 已经访问过直接返回
	if (visted[id] == 1) return;
	
	visted[id] = 1;
	val += employee->importance;
	
	for (int num: employee->subordinates) {
		Employee* p;
		// 找到id为num的employee
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i]->id == num) {
				p = employees[i];
				break;
			}
		}
		dfs(employees, p, visted, val, p->id);
	}
}

int getImportance(vector<Employee*> employees, int id) {
	if (employees.empty()) return 0;
	
	const int size = employees.size();  // 总员工数字
	vector<int> visited(2001, 0);  // 标记员工是否被访问过
	
	// 深度优先搜索
	int val = 0;
	for (int i = 0; i < size; ++i) {
		if (employees[i]->id == id) 
			dfs(employees, employees[i], visited, val, id);
	}
	return val;
}

int main() {
	// 手动创建测试用例
	Employee* p1 = new Employee();  // p1
	p1->id = 1;
	p1->importance = 5;
	Employee* p2 = new Employee();  // p2
	p2->id = 2;
	p2->importance = 3;
	Employee* p3 = new Employee();  // p3
	p3->id = 3;
	p3->importance = 3;
	
	p1->subordinates = {2, 3};
	vector<Employee*> employees = {p1, p2, p3};
	
	// 计算重要性
	int val = getImportance(employees, 1);
	cout << val << endl;
	
	return 0;
}