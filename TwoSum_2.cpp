//============================================================================
// Name        : TwoSum_2.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/.
//============================================================================
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int l = 0, r = numbers.size() - 1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                v.push_back(l+1);
                v.push_back(r+1);
                return v;
            }
            else if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return v;
    }
};


int main(){
    Solution *solution = new Solution();
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = solution->twoSum(nums,target);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }

}