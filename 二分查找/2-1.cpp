/*
 * 题目：在排序数组中查找元素的第一个和最后一个位置
 * 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

#include <iostream>
#include <vector>

using namespace std;

int searchLeft(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 找到target但不能保证是左边第一个，所以要缩小区间继续寻找。
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    if (left != nums.size() && nums[left] == target)
        return left;
    // 下标越界
    return -1;
}

int searchRight(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 找到target但不能保证是右边最后一个，所以要缩小区间继续寻找。
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

    return right;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    if (nums.size() == 0)
        return { -1, -1 };

    int left = searchLeft(nums, target);
    if (left == -1)
        return { -1, -1 };
    else
        return { left, searchRight(nums, target) };
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

    // 查找位置
    vector<int> res = searchRange(nums, target);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
