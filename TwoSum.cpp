//============================================================================
// Name        : TwoSum.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an array of integers nums and an integer target, 
//               return indices of the two numbers such that they add up to target.
//============================================================================
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        
        for(int i =0; i<nums.size();i++){
            if(myMap.find(target-nums[i]) != myMap.end()){
                return {i,myMap[target-nums[i]]};
            }
            myMap[nums[i]] = i;
        }
        
        return {};
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