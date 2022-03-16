//============================================================================
// Name        : MaximumSubarray.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an integer array nums, find the contiguous subarray 
//               (containing at least one number) which has the largest sum and return its sum.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxGlobal = nums[0];
        int maxCurrent = nums[0];
        for(int i=1; i < nums.size(); i++){
            maxCurrent = max(nums[i], maxCurrent+nums[i]);
            maxGlobal = max(maxGlobal,maxCurrent);
        }
        return maxGlobal;
    }
};

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    Solution *solution = new Solution();
    cout << solution->maxSubArray(arr);
}