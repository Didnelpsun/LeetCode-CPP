#include <vector>
#include <iostream>
#include "../source/1-twoSum.cpp"

using namespace std;

int test_1()
{
    vector<int> nums;
    vector<int> result;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    result = twoSum(nums, target);
    return 0;
}