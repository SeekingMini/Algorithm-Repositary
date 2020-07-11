/*
 * 题目：字符串压缩
 * 链接：https://leetcode-cn.com/problems/compress-string-lcci/
 */

#include <string>
#include <iostream>

using namespace std;

string compressString(string S)
{
    if (S.empty())
        return 0;

    int l = S.length(); // 字符串长度
    int start = 0;      // 快指针
    int end = 0;        // 慢指针
    string new_S = "";

    while (start != l)
    {
        while (S[start] == S[end])
        {
            end++;
        }
        new_S += S[start];
        new_S += to_string(end - start);
        start = end;
    }

    if (new_S.length() >= l) return S;
    else return new_S;
}

int main()
{
    string S;
    cin >> S;

    string compressed = compressString(S);
    cout << compressed << endl;

    return 0;
}