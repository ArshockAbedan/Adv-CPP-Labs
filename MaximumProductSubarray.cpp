//============================================================================
// Name        : MaximumProductSubarray.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an integer array nums, find a contiguous non-empty subarray
//                within the array that has the largest product, and return the product.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        auto max_iterator = max_element(nums.begin(), nums.end());  // iterator that has max value
        long long res = *max_iterator; // value of max_iterator
        long long currMax = 1;
        long long currMin = 1;
        long long n = nums[0]; // for converting items from int to long long
        long long temp = 1; // for storing previous value of currMax

        for (int i = 0; i < nums.size(); i++)
        {
            n = nums[i];
            temp = n * currMax;
            currMax = max({n * currMax, n * currMin, n});
            currMin = min({temp, n * currMin, n});
            res = max(res, currMax);
        }

        return res;
    }
};

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    Solution *solution = new Solution();
    cout << solution->maxProduct(arr);
}