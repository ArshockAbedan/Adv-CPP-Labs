//============================================================================
// Name        : MaximumLengthofSubarrayWithPositiveProduct.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an array of integers nums, find the maximum length 
//               of a subarray where the product of all its elements is positive.
//               Return the maximum length of a subarray with positive product.
//============================================================================
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = 0, p = 0, result = 0;  // n: # of Negatives, p: # of Positives  
        for(int &x: nums){
            if(x==0) p=0,n=0;
            else if(x>0){
                p++, n += (n>0);
            }else{
                int temp = p;
                p = n + (n>0);
                n = temp + 1;
            }
            result = max(result,p);
        }
        return result;
        
    }
};


int main()
{
    vector<int> arr = {1,-2,-3,4};
    int k = 3;
    Solution *solution = new Solution();
    cout << solution->getMaxLen(arr);
}