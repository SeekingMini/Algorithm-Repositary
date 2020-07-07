/*
 * 题目：跳跃游戏
 * 链接：https://leetcode-cn.com/problems/jump-game/
 */
#include <vector>
#include <iostream>
using namespace std;

bool canJump(vector<int> &nums)
{
    int farthest = 0;  // 对于全局来说可以到达的最大距离
    for (int i = 0; i < nums.size(); i++)
    {
        if (farthest < i) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

int main()
{
    int n;
    vector<int> nums;

    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
            break;
    }

    bool jump = canJump(nums);
    cout << jump << endl;

    return 0;
}