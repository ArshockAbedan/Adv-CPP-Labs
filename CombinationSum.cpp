//============================================================================
// Name        : CombinationSum.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/combination-sum/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination, int i)
    {
        if (target == 0)
        {
            // if we get exact answer
            res.push_back(combination);
            return;
        }

        while (i < candidates.size() && target - candidates[i] >= 0)
        {
            // Till every element in the array starting
            // from i which can contribute to the target
            combination.push_back(candidates[i]); // add them to vector

            // recur for next numbers
            dfs(candidates, target - candidates[i], res, combination, i);
            i++;

            // Remove number from vector (backtracking)
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end()); // sort candidates array
        
        // remove duplicates
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        vector<int> combination;
        vector<vector<int>> res;

        dfs(candidates, target, res, combination, 0);

        return res;
    }
};


int main()
{
    vector<int> candidates = {2,3,5};
    int target = 8;
    Solution *solution = new Solution();
    vector<vector<int>> result=  solution->combinationSum(candidates,target);
    for(vector<int> res : result){
        cout << "[" << res[0];
        for(int i=1; i<res.size(); i++){
            cout << ", " << res[i];
        }
        cout << "]" << endl;
    }
    return 0;
}