//============================================================================
// Name        : LongestPalindromicSubstring.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given a string s,
//               return the longest palindromic substring in s.
//============================================================================
#include <iostream>
using namespace std;

class Solution
{
private:
    void findLongestPalindrome(int &l, int &r, int &resLen, string &res, string &s)
    {
        // In Odd e.g. 'bab' and Even e.g. 'bb',
        // we need s[l] == s[r] to consider it as valid as well as
        // 0 < sliding window < s.length()
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            // its a valid(Palindrome) substr, so check its size with global max length.
            if ((r - l + 1) > resLen)
            {
                res = s.substr(l, r - l + 1);
                resLen = r - l + 1;
            }
            // starting from center, expand into both directions.
            l--;
            r++;
        }
    }

public:
    string longestPalindrome(string s)
    {
        string res = ""; // output
        int resLen = 0;  // global max length
        int l, r;        // leftIndex and rightIndex of sliding window

        for (int i = 0; i < s.length(); i++)
        {
            // Odd length
            l = i;
            r = i;
            findLongestPalindrome(l, r, resLen, res, s);

            // Even length
            l = i;
            r = i + 1;
            findLongestPalindrome(l, r, resLen, res, s);
        }
        return res;
    }
};

int main()
{
    string myStr = "babad";
    Solution *solution = new Solution();
    cout << solution->longestPalindrome(myStr);
}