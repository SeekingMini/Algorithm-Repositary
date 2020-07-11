/*
 * 区域和检索 - 数组不可变
 */
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class NumArray
{
private:
    vector<int> dp; // dp[i]表示从索引0到i范围内元素的总和

public:
    NumArray(vector<int> &nums)
    {
        int l = nums.size();
        dp.push_back(0); // dp[0] = 0
        for (int i = 0; i < l; i++)
        {
            dp.push_back(dp[i] + nums[i]);
        }
    }

    int sumRange(int i, int j)
    {
        return dp[j + 1] - dp[i];
    }
};

int main()
{
    vector<int> nums;
    int n;

    // 输入数组
    while (cin >> n)
    {
        nums.push_back(n);
        if (getchar() == '\n')
            break;
    }

    NumArray *obj = new NumArray(nums);
    int param_1 = obj->sumRange(0, 2);
    int param_2 = obj->sumRange(2, 5);
    int param_3 = obj->sumRange(0, 5);
    printf("%d %d %d\n", param_1, param_2, param_3);

    return 0;
}
