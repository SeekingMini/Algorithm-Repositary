/*
 * 题目：等式方程的可满足性
 * 链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 并查集（未优化）
class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }

    void connect(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP != rootQ)
            parent[rootP] = rootQ;
    }

    int find(int x)
    {
        while (x != parent[x])
            x = parent[x];

        return x;
    }
};

bool equationsPossible(vector<string> &equations)
{
    UnionFind uf(26);

    // 首先把等式两边的字符合并到一棵树
    for (auto equation : equations)
    {
        char c1 = equation[0];
        char c2 = equation[3];

        if (equation[1] == '=')
            uf.connect(c1 - 'a', c2 - 'a');
    }

    // 判断
    for (auto equation : equations)
    {
        char c1 = equation[0];
        char c2 = equation[3];

        if (equation[1] == '!')
        {
            if (uf.find(c1) == uf.find(c2))
                return false;
        }
    }
    return true;
}

int main()
{
    // 手动创建测试数据
    vector<string> equations;
    equations.push_back("a==b");
    equations.push_back("b==c");
    equations.push_back("c==d");
    equations.push_back("a==d");

    // 判断
    bool flag = equationsPossible(equations);
    cout << flag << endl;

    return 0;
}