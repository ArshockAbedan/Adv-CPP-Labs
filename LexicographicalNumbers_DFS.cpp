//============================================================================
// Name        : LexicographicalNumbers_DFS.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an integer n,
//               return all the numbers in the range [1, n] sorted in lexicographical order.
//============================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> sol;
        dfs(1, n, sol);
        return sol;
    }
    
    // Depth-first search
    void dfs(int temp, int n, vector<int> &sol)
    {
        if (temp > n)
        {
            return;
        }
        sol.push_back(temp);
        dfs(temp * 10, n, sol); // go for adding next digit to the n
        if (temp % 10 != 9)  // if the number of digits in n will be changed 
        {
            dfs(temp + 1, n, sol); // go for next number with same amount of digits.
        }
    }
};

int main()
{
    Solution *solution = new Solution();
    int n = 13;
    vector<int> res = solution->lexicalOrder(n);
    if (!res.empty())
    {
        cout << "[" << res[0];
        for (int i = 1; i < res.size(); i++)
        {
            cout << ", " << res[i];
        }
        cout << "]";
    }
    else
    {
        cout << "[]";
    }
}