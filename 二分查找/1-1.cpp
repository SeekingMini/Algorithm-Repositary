/*
 * 题目：搜索插入位置
 * 链接：https://leetcode-cn.com/problems/search-insert-position/
 */

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int res = -1;

    // 首先尝试在数组中找到target。
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            res = mid;
            break;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }

    // 如果找到，直接返回下标。
    if (res != -1) return res;
    else return left;
}

int main()
{
    int n, target;
    vector<int> nums;

    // 输入数据
    cin >> target;
    while (cin >> n) {
        nums.push_back(n);

        if (getchar() == '\n')
            break;
    }

    // 搜索插入位置
    int index = searchInsert(nums, target);
    cout << index << endl;

    return 0;
}
