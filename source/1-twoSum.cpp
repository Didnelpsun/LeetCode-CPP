// 给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

#include <vector>
#include <iostream>

using namespace std;

// 简单思路就是从第一个开始然后依次相加，比较目标值
// 需要进行两层循环

int *twoSumAdd(const int *nums, int target) {
    int i, j;
    int size = sizeof nums;
    // 初始化result，其中初始值为两个-1
    // 加上static表示是静态的，在堆区而不是栈区
    static int result[2] = {-1, -1};
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
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
int *twoSumSub(const int *nums, int target) {
    int i, j, temp;
    unsigned int size = sizeof nums;
    // 初始化result，其中初始值为两个-1
    static int result[2] = {-1, -1};
    for (i = 0; i < size - 1; i++) {
        temp = target - nums[i];
        for (j = i + 1; j < size; j++) {
            if (temp == nums[j]) {
                result[0] = i;
                result[1] = j;
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

int *getTwoSum(int *nums, int target) {
    return twoSumSub(nums, target);
}

void twoSum(int *nums, int target) {
    cout << "题目:给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。"
         << endl;
    cout << "输入:[";
    for (int i = 0; i < sizeof nums; i++) {
        cout << nums[i];
        if (i != sizeof nums - 1)
            cout << ",";
    }
    cout << "]" << endl;
    cout << "输出:" << target << endl;
    int *result = getTwoSum(nums, target);
    cout << "说明:元素" << result[0] << "+" "元素" << result[1] << "=" << target << target;
}