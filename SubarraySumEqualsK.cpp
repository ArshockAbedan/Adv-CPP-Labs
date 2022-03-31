//============================================================================
// Name        : SubarraySumEqualsK.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/subarray-sum-equals-k/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // with help of prefix_sum
        unordered_map<int, int> seen = {{0, 1}};
        // key: sum_till_now
        // value: how many time it is calculated.
        int sum = 0, res = 0;
        for (auto it : nums)
        {
            sum += it;
            int complement = sum - k;
            if (seen.find(complement) != seen.end())
            {
                res += seen[complement];
            }
            seen[sum]++;
        }
        return res;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    int k = 3;
    Solution *solution = new Solution();
    cout << solution->subarraySum(arr, k);
    return 0;
}