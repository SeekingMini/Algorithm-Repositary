/*
 * 题目：除数博弈
 * 链接：https://leetcode-cn.com/problems/divisor-game/
 */

#include <vector>
#include <iostream>

using namespace std;

bool divisorGame(int N)
{
    if (N == 1)
        return false;
    if (N == 2)
        return true;

    // dp[i]表示当数字为N时。爱丽丝是否能赢。
    // 如果赢，dp[i] = 1；
    // 如果输，dp[i] = 0。
    vector<int> dp(N + 1, 0);

    for (int i = 2; i <= N; i++)
    {
        for (int x = 1; x < i; x++)
        {
            if (i % x == 0 && !dp[i - x])
            {
                dp[i] = 1;
            }
        }
    }
    return dp[N];
}

int main()
{
    int N;

    // 输入数据
    cin >> N;

    // 判断
    bool win = divisorGame(N);
    cout << win << endl;

    return 0;
}