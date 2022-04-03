//============================================================================
// Name        : Gas_Station.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/gas-station/
//============================================================================
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // first of all we need to check whether we've sfficient fuel or not.
        int total_cost = 0, total_fuel = 0, n = cost.size();
        for (int i = 0; i < n; i++)
        {
            total_cost += cost[i];
            total_fuel += gas[i];
        }
        // If the total fuel is lesser than the cost then definitely we can't cover the whole cicular tour.
        if (total_fuel < total_cost)
        {
            return -1;
        }

        // If the total fuel is sufficient enough to cover the circular tour then definitely an answer exists
        int curr_fuel = 0, start = 0; // start with zero fuel.
        for (int i = 0; i < n; i++)
        {
            // If at any point our balance/ current fuel is negative that means we can't come to the i'th petrol pump from the previous pump beacuse our fuel won't allow us to cover such distance.
            // So we'll make the i'th pump as the start point ans proceed. Simultaneously we'll make the current fuel to be 0 as we're starting freshly.
            if (curr_fuel < 0)
            {
                start = i;
                curr_fuel = 0;
            }
            // at any station we'll fill petrol and pay the cost to go to the next station . so current fuel would be the following.
            curr_fuel += (gas[i] - cost[i]);
        }
        return start;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution *solution = new Solution();
    cout << solution->canCompleteCircuit(gas, cost);
    return 0;
}