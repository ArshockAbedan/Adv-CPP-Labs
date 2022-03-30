//============================================================================
// Name        : MaximumUnitsTruck.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/maximum-units-on-a-truck/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    bool static comparator(vector<int> &x, vector<int> &y)
    {
        return (x[1] > y[1]);
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int res = 0; // total units

        for (int i = 0; i < boxTypes.size(); i++)
        {
            int box_count = min(boxTypes[i][0], truckSize);
            res += box_count * boxTypes[i][1];
            truckSize -= box_count;
            if (truckSize == 0)
                break;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    int truckSize = 10;
    Solution *solution = new Solution();
    cout << solution->maximumUnits(boxTypes, truckSize);
    return 0;
}