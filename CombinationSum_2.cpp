//============================================================================
// Name        : CombinationSum_2.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/combination-sum-ii/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void dfs(int index, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &combination)
    {
        // base case
        // when the combination ds is carrying is a valid one add it into th res
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
            {
                // no point of it to add it to the res
                // if the candidate at ith element exceeds the target
                // no picking up hence break
                break;
            }
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            // to avoid picking up the same elements and thus avoiding duplicates (no picking of element)
            combination.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], candidates, res, combination); // call for next element
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        dfs(0, target, candidates, res, combination);
        return res;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution *solution = new Solution();
    vector<vector<int>> result = solution->combinationSum2(candidates, target);
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