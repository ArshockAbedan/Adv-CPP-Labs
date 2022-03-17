//============================================================================
// Name        : MinimumSizeSubarraySum.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an array of positive integers nums and a positive integer target,
//               return the minimal length of a contiguous subarray
//               of which the sum is greater than or equal to target.
//               If there is no such subarray, return 0 instead.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minWindowSize = INT_MAX;
        int currentWindowSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            currentWindowSum += nums[windowEnd];
            while (currentWindowSum >= target)
            {
                minWindowSize = min(minWindowSize, windowEnd - windowStart + 1);
                currentWindowSum -= nums[windowStart];
                windowStart++;
            }
        }

        if (minWindowSize == INT_MAX)
        {
            return 0;
        }
        return minWindowSize;
    }
};

int main()
{
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution *solution = new Solution();
    cout << solution->minSubArrayLen(target, arr);
}