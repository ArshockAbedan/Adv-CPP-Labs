//============================================================================
// Name        : LongestConsecutiveSequence.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/longest-consecutive-sequence/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(begin(nums), end(nums));
        int longest = 0;
        for (auto &num : s)
        {
            if (!s.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (s.count(currentNum + 1))
                {
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << solution->longestConsecutive(arr);
    return 0;
}