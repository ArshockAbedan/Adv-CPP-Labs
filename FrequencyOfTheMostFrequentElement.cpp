//============================================================================
// Name        : FrequencyOfTheMostFrequentElement.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : The frequency of an element is the number of times it occurs in an array.
//               You are given an integer array nums and an integer k. In one operation, 
//               you can choose an index of nums and increment the element at that index by 1.
//               Return the maximum possible frequency of an element after performing at most k operations.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        // with help of sliding window
        int l = 0; // left index
        int r = 0; // right index
        int total = 0; // total sum of elements inside the window
        int res = 0; // output

        
        // sort the array
        sort(nums.begin(), nums.end());

        while (r < nums.size())
        {
            
            // add current element to total
            total += nums[r];

            // (r - l + 1) is window lenght
            // nums[r] * (r - l + 1) is post condition, after change all elements
            //  total is current sum and k is our budget for changing value of elements
            while (nums[r] * (r - l + 1) > total + k)
            {
                total -= nums[l];
                l += 1;
            }
            // res = max(res, r - l + 1)
            if (res < r - l + 1)
            {
                res = r - l + 1;
            }
            r += 1; // the next step for main while loop
        }

        return res;
    }
};

int main()
{

    vector<int> nums = {9930, 9923, 9983, 9997, 9934, 9952, 9945, 9914, 9985, 9982, 9970,
                        9932, 9985, 9902, 9975, 9990, 9922, 9990, 9994, 9937, 9996, 9964, 9943, 9963, 9911,
                        9925, 9935, 9945, 9933, 9916, 9930, 9938, 10000, 9916, 9911, 9959, 9957, 9907, 9913,
                        9916, 9993, 9930, 9975, 9924, 9988, 9923, 9910, 9925, 9977, 9981, 9927, 9930, 9927,
                        9925, 9923, 9904, 9928, 9928, 9986, 9903, 9985, 9954, 9938, 9911, 9952, 9974, 9926,
                        9920, 9972, 9983, 9973, 9917, 9995, 9973, 9977, 9947, 9936, 9975, 9954, 9932, 9964,
                        9972, 9935, 9946, 9966};
    int k = 3056;
    // vector<int> nums = {1, 4, 5, 13};
    // int k = 5;
    Solution *solution = new Solution();
    cout << solution->maxFrequency(nums, k);
    return 0;
}