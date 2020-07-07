/*
 * 题目：每日温度
 * 链接：https://leetcode-cn.com/problems/daily-temperatures/
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T)
{
    vector<int> ans(T.size());
    stack<int> st;

    for (int i = T.size() - 1; i >= 0; i--) {
        while (!st.empty() && T[st.top()] <= T[i])
            st.pop();
        ans[i] = st.empty() ? 0 : (st.top() - i);
        st.push(i);
    }
    return ans;
}

int main()
{
    int n;
    vector<int> nums;

    // 输入数据
    while (cin >> n) {
        nums.push_back(n);

        if (getchar() == '\n')
            break;
    }

    // 计算
    vector<int> ans = dailyTemperatures(nums);
    for (int num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}