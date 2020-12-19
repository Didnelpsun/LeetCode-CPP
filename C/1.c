//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//链接：https ://leetcode-cn.com/problems/two-sum
//示例:
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]

#include<stdio.h>
#include<stdlib.h>
#define size 4

// 官方的暴力枚举法
//因为C语言中数组一般都需要提前分配内存，所以除了两个必须参数外还需要一个参数numsSize控制数组长度
//int*表示这个变量为一个指向int类型的指针
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //首先从0开始遍历nums数组中的所有数字
    for (int i = 0; i < numsSize; ++i) {
        //因为是枚举，所以从当前遍历的变量开始的后一个变量检测是否能得到target值
        for (int j = i + 1; j < numsSize; ++j) {
            //如果这两个值相等，即得到想要的值
            if (nums[i] + nums[j] == target) {
                //定义一个中间变量并使用malloc方法来拓展两个数组的指针
                int* ret = malloc(sizeof(int) * 2);
                //进行赋值
                ret[0] = i, ret[1] = j;
                //然后对这个传入的参数指针returnSize赋值为2
                *returnSize = 2;
                return ret;
            }
        }
    }
    //如果没有找到对应的值就返回returnSize和一个Null
    *returnSize = 0;
    return NULL;
}
//所以我觉得returnSize这个变量设置的就很奇怪，这个题目的意思就是需要我们改变这个传入的参数，如果存在能相加得到target的值，就将这个值设置为2，如果没有就设置为0
//注意C语言与其他一些高级语言不同的是，不能直接更改参数数值，而必须使用指针来改变

int main() {
    int nums[size] = { 2, 7, 11, 15 };
    int target = 9;
    int returnSize;
    int* returnNums;
    returnNums = twoSum(nums, size, target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("第%d个元素的索引为%d，值为%d\n", i+1, returnNums[i], nums[i]);
    }
    if (returnSize == 0) {
        printf("无法相加得到目标%d", target);
    }
    return 0;
}