//============================================================================
// Name        : CombinationSum.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/combination-sum-iii/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> res;

    void dfs(vector<int> &combination, int cnum, int k, int n)
    {
        if (n < 0 || combination.size() > k)
            return;
        if (n == 0 && combination.size() == k)
        {
            res.push_back(combination);
            return;
        }

        for (int i = cnum; i <= 9; ++i)
        {
            combination.push_back(i);
            dfs(combination, i + 1, k, n - i);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> combination;
        dfs(combination, 1, k, n);
        return res;
    }
};

int main()
{
    int k = 3;
    int n = 9;
    Solution *solution = new Solution();
    vector<vector<int>> result = solution->combinationSum3(k, n);
    for (vector<int> res : result)
    {
        cout << "[" << res[0];
        for (int i = 1; i < res.size(); i++)
        {
            cout << ", " << res[i];
        }
        cout << "]" << endl;
    }
    return 0;
}