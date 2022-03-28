//============================================================================
// Name        : maxProfit.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : You are given an array prices where prices[i]
//               is the price of a given stock on the ith day. You want to maximize 
//               your profit by choosing a single day to buy one stock and choosing 
//               a different day in the future to sell that stock.
//============================================================================
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow= INT_MAX; // Min that we observe till now
        int maxProfit=0; // max possible profit from start till now.
        for(int i=0; i<prices.size(); i++){
            minTillNow= min(minTillNow, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minTillNow);  // profit means current value - globalMin
        }
        return maxProfit;
    }
};


int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    Solution *solution = new Solution();
    cout << solution->maxProfit(arr);

}