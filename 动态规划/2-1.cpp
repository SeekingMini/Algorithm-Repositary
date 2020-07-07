/*
 * 题目：丑数 II
 * 链接：https://leetcode-cn.com/problems/ugly-number-ii/
 */
#include <vector>
using namespace std;

int getMin(int a, int b, int c)
{
    int n = (a < b) ? a : b;
    n = (n < c) ? n : c;
    return n;
}
int nthUglyNumber(int n)
{
    if (n == 1)
        return 1;

    // dp[i]表示第i个丑数
    vector<int> dp(1690, 0);
    dp[0] = 1; // 第1个丑数是1
    int *m2 = &dp[0];
    int *m3 = &dp[0];
    int *m5 = &dp[0];

    int nextindex = 1;
    while (nextindex < n)
    {
        int minNum = getMin(*m2 * 2, *m3 * 3, *m5 * 5);
        dp[nextindex] = minNum;
        while ((*m2 * 2) <= minNum)
            m2++;
        while ((*m3 * 3) <= minNum)
            m3++;
        while ((*m5 * 5) <= minNum)
            m5++;
        nextindex++;
    }
    return dp[n - 1];
}