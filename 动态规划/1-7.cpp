/*
 * 题目：三步问题
 * 链接：https://leetcode-cn.com/problems/three-steps-problem-lcci/
 */

#include <vector>
#include <iostream>

using namespace std;

int waysToStep(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    long long a = 1, b = 2, c = 4;
    long long res = 0;
    for (int i = 4; i <= n; i++)
    {
        res = (a + b + c) % 1000000007;
        a = b;
        b = c;
        c = res;
    }
    return res % 1000000007;
}

int main()
{
    int steps;

    // 输入数据
    cin >> steps;

    int ways = waysToStep(steps);
    cout << ways << endl;

    return 0;
}