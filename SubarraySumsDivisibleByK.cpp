//============================================================================
// Name        : SubarraySumsDivisibleByK.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/subarray-sums-divisible-by-k/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int pref = 0;         // prefix sum
        vector<int> cPref(k); // sum will not exceed k as we are taking modulo at every step
        cPref[pref]++;        // adding 0 as prefix sum, base case

        int res = 0; // count of number of subarrays whose sum is divisible by K

        for (int i = 0; i < nums.size(); i++)
        {

            pref = (pref + nums[i]) % k; // Here, we take modulo of prefix sum as outlined in the explanation

            if (pref < 0)
                pref += k; // since -1 mod 5 and 4 mod 5 are equivalent, we will keep only positives since we like them :)

            res += cPref[pref]; // if we have already found pref, then increase the answer count

            cPref[pref]++; // add pref seen count by 1
        }

        return res;
    }
};

int main()
{
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int k = 5;
    Solution *solution = new Solution();
    cout << solution->subarraysDivByK(arr, k);
    return 0;
}