//============================================================================
// Name        : ThirdMaximumNumber.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an integer array nums,
//               return the third distinct maximum number in this array.
//                If the third maximum does not exist, return the maximum number.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // get unique values of sorted vector
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        if (n < 3) // If the third maximum does not exist
        {
            return nums[n - 1]; // the maximum number
        }
        return nums[n - 3]; // the third distinct maximum number
    }
};

int main()
{
    vector<int> arr = {2, 2, 3, 1};
    Solution *solution = new Solution();
    cout << solution->thirdMax(arr);
}