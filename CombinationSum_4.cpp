//============================================================================
// Name        : CombinationSum_4.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/combination-sum-iv/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        /* sorting is used to minimize the runtime for iterating through the nums.
            Once we reach a number greater than the target that we are looking for,
            there's no need to search for the rest.
        */
        sort(nums.begin(), nums.end());
        // use unsigned long to prevent integer overflow
        vector<unsigned long> dp(target + 1, 0);
        // standing on the ground also count as one way.
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
        {
            int ways = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                int remain = i - nums[j];
                if (remain < 0)
                    break;
                // the way it can reach the point are always start from the smaller number
                ways += dp[remain];
            }
            dp[i] = ways;
        }
        return dp[target];
    }
};

int main()
{
    vector<int> candidates = {1, 2, 3};
    int target = 4;
    Solution *solution = new Solution();
    cout << solution->combinationSum4(candidates, target);
}