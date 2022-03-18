//============================================================================
// Name        : GenerateAllPalindromicNumsLessThanN.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Count the number of palindromic numbers less than N.
//============================================================================
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int palindromicNumbers(int N)
    {
        stack<char> myStack;
        int res = 0;
        string preStr = "";
        string postStr = "";
        for (int i = 1; i < N; i++)
        {
            if (i < 10)
            {
                res++;
            }
            else
            {
                preStr = to_string(i);
                for (char ch : preStr)
                {
                    myStack.push(ch);
                }
                while (!myStack.empty())
                {
                    postStr += myStack.top();
                    myStack.pop();
                }
                if (preStr == postStr)
                {
                    res++;
                }
                preStr = "";
                postStr = "";
            }
        }
        return res;
    }
};


int main(){
    Solution *solution = new Solution();
    int n = 12;
    cout << solution->palindromicNumbers(n);
    return 0;
}