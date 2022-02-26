//============================================================================
// Name        : MaximumLengthOfAConcatenatedStringWithUniqueCharacters.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : You are given an array of strings arr. 
//               A string s is formed by the concatenation of a subsequence of arr 
//               that has unique characters.
//               Return the maximum possible length of s.
//============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
 
int maxLength(vector<string>& arr)
{
    vector<bitset<26>> dp = { bitset<26>() }; // auxillary dp storage
    int res = 0; // will store number of unique chars in
                 // resultant string
    for (auto& word : arr) {
        bitset<26> UniqueCharsofWord; // used to track unique chars
        for (char c : word)
            UniqueCharsofWord.set(c - 'a');
        int n = UniqueCharsofWord.count();
        if (n < word.size())
            continue; // duplicate chars in current string
 
        for (int i = dp.size() - 1; i >= 0; --i) {
            bitset<26> current = dp[i];
            if ((current & UniqueCharsofWord).any())
                continue; // if 1 or more char common
            dp.push_back(current | UniqueCharsofWord); // valid concatenation
            res = max(res, (int)current.count() + n);
        }
    }
    return res;
}
 
int main()
{
    vector<string> v = { "aa", "bb"};
    int ans = maxLength(v);
    cout << ans; // resultant answer string : cfbdghzest
    return 0;
}


