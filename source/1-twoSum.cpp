// 给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

#include <vector>

using namespace std;

// 简单思路就是从第一个开始然后依次相加，比较目标值
// 需要进行两层循环

vector<int> twoSumAdd(vector<int> &nums, int target)
{
    int i, j;
    int size = nums.size();
    // 初始化result，其中初始值为两个-1
    vector<int> result(2, -1);
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.clear();
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

// 执行用时：
// 364 ms
// , 在所有 C++ 提交中击败了
// 14.72%
// 的用户
// 内存消耗：
// 9.8 MB
// , 在所有 C++ 提交中击败了
// 89.87%
// 的用户

// 进一步改进是将目标值与当前遍历值相减再比较当前值后面的所有值，这就不用每次都相加比较了
vector<int> twoSumSub(vector<int> &nums, int target)
{
    int i, j, temp;
    int size = nums.size();
    // 初始化result，其中初始值为两个-1
    vector<int> result(2, -1);
    for (i = 0; i < size - 1; i++)
    {
        temp = target - nums[i];
        for (j = i + 1; j < size; j++)
        {
            if (temp == nums[j])
            {
                result.clear();
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

// 执行用时：
// 192 ms
// , 在所有 C++ 提交中击败了
// 42.83%
// 的用户
// 内存消耗：
// 9.8 MB
// , 在所有 C++ 提交中击败了
// 87.08%
// 的用户

vector<int> twoSum(vector<int> &nums, int target)
{
    return twoSumSub(nums, target);
}