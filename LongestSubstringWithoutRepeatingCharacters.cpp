//============================================================================
// Name        : LongestSubstringWithoutRepeatingCharacters.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given a string s,
//               find the length of the longest substring without repeating characters.
//============================================================================
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;    // Max global length of substrs
        set<int> mySet; // to reserve unique chars
        int l = 0;      // left index of silding window
        for (int r = 0; r < s.length(); r++)
        { // r is right index of sliding window
            // when substr doesnot contain unique chars anymore
            while (mySet.find(s[r]) != mySet.end())
            {
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            res = max(res, r - l + 1); // max current res and size of valid sliding window
        }
        return res;
    }
};

int main()
{
    string myStr = "abcabcbb";
    Solution *solution = new Solution();
    cout << solution->lengthOfLongestSubstring(myStr);
}
