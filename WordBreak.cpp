//============================================================================
// Name        : WordBreak.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given a string s and a dictionary of strings wordDict,
//               return true if s can be segmented into
//               a space-separated sequence of one or more dictionary words.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int len = s.length();  // length of string
        // Dynamic Programing: a vector of boolean which each element contains true tell us
        // that to the position of that element, we can segment string using provided dictionry.
        vector<bool> dp(len + 1, false); 
        dp[0] = true; // it should return true for an empty string.

        // First Optimization: if used max length of words in dictionary 
        // to consider the largest possible word in string.  
        int maxLen = 0;
        for (string word : wordDict)
        {
            maxLen = max(maxLen, static_cast<int>(word.length()));
        }

        for (int i = 0; i <= len; i++)
        {
            // second optimization: start j from nearest index to i and go to the begining of string.
            for (int j = i - 1; j >= 0; j--) 
            {
                if (i - j > maxLen)
                {
                    // if current segmented word is larger that maxLen, ignore it.
                    continue;
                }

                // if jth element in dp is true and
                // if you can find current word (string from j to i-j) in dictionary
                // then you can segment string to ith position using words in dictionary
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        // based on definition of dp, if last element is true,
        // we can segment the string using words in dictionary.
        return dp[len];
    }
};

int main()
{

    string s = "applepenapple";
    vector<string> wordDict;
    wordDict.push_back("apple");
    wordDict.push_back("pen");
    Solution *solution = new Solution();
    bool result = solution->wordBreak(s, wordDict);
    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}
