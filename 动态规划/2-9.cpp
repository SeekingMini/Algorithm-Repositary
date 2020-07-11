/*
 * 题目：最长回文子序列
 * 链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s)
{
    int l = s.size();
    // dp[i][j]表示字串s[i...j]中最长回文子序列的长度
    vector<vector<int>> dp(l, vector<int>(l, 0));

    // 初始化
    for (int i = 0; i < l; i++)
        dp[i][i] = 1;

    // 反向遍历数组(很关键)
    for (int i = l - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < l; j++)
        {
            // 状态转移方程
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][l - 1];
}

int main()
{
    string s;

    // 输入数据
    cin >> s;

    // 计算最长回文子序列
    int max_length = longestPalindromeSubseq(s);
    printf("%d\n", max_length);

    return 0;
}