//============================================================================
// Name        : MusicPairs.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        unordered_map<int, int> mp;
        int n = time.size();
        int res = 0;
        int reminder = 0;

        for (int i = 0; i < n; i++)
        {
            reminder = time[i] % 60;

            if (reminder == 0)
            {
                res += mp[0];
            }
            else
            {
                res += mp[60 - reminder];
            }
            mp[reminder]++;
        }

        return res;
    }
};

int main()
{
    vector<int> arr = {30, 20, 150, 100, 40};
    Solution *solution = new Solution();
    cout << solution->numPairsDivisibleBy60(arr);
    return 0;
}