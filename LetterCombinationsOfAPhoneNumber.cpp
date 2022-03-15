//============================================================================
// Name        : LetterCombinationsOfAPhoneNumber.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given a string containing digits from 2-9 inclusive,
//               return all possible letter combinations that the number could represent.
//               Return the answer in any order.
//============================================================================
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) return result;
        string map[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",               "wxyz"};
        result.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> temp;
            string chars = map[digits[i] - '0'];
            for (int c = 0; c < chars.size();c++)
                for (int j = 0; j < result.size();j++)
                    temp.push_back(result[j]+chars[c]);
            result.swap(temp);
        }
        return result;
    }
    
};

int main()
{
    Solution *solution = new Solution();
    vector<string> res = solution->letterCombinations("23");
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
}