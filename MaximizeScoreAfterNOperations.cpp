//============================================================================
// Name        : MaximizeScoreAfterNOperations.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : You are given nums, an array of positive integers of size 2 * n.
//               You must perform n operations on this array.
//               In the ith operation (1-indexed), you will:
//               * Choose two elements, x and y.
//               * Receive a score of i * gcd(x, y).
//               * Remove x and y from nums.
//               Return the maximum score you can receive after performing n operations.
//               The function gcd(x, y) is the greatest common divisor of x and y.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
private:
    int dp[1 << 14];
    int solve(vector<int> &arr, int mask, int n)
    {
        if (mask == 0)
        {
            return 0;
        }
        int &res = dp[mask];
        if (res > -1)
            return res;
        int k = 1 + (n - (__builtin_popcount(mask))) / 2;
        res = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if ((mask >> j) & 1)
                    {
                        res = max(res, k * __gcd(arr[i], arr[j]) + solve(arr, mask ^ (1 << i) ^ (1 << j), n));
                    }
                }
            }
        }
        return res;
    }

public:
    int maxScore(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int mask = (1 << n) - 1;
        return solve(nums, mask, n);
    }
};

int main()
{
    vector<int> arr = {3, 4, 6, 8};
    Solution *solution = new Solution();
    cout << solution->maxScore(arr);
    return 0;
}