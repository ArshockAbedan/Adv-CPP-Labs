//============================================================================
// Name        : MaxSumSubArray.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : You are given an array nums and a size k for possible subarrays.
//               return maximum sum over all possible subarrays.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxSumSubarray(vector<int> nums, int k)
    {
        int maxSum = INT_MIN; // max Sum over all possible subarrays
        int currentRunningSum = 0; // sum of all elements in current subarrays.
        for(int i = 0; i < nums.size(); i++){
            currentRunningSum +=nums[i];
            // before reaching to size of k, just sum up all elements in current subarray
            if(i > k-1){
                maxSum = max(maxSum, currentRunningSum);
                // sliding window is shifted to right, 
                // so first element in prevoius subarray is not in current subarray anymore. 
                currentRunningSum = nums[i-(k-1)];
            }
        }
        return maxSum;
    }
};

int main()
{
    vector<int> arr = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int k = 3;
    Solution *solution = new Solution();
    cout << solution->findMaxSumSubarray(arr, k);
}
