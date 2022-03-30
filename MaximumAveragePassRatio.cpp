//============================================================================
// Name        : MaximumAveragePassRatio.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/maximum-average-pass-ratio/
//============================================================================
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

class Solution
{
    double profit(double pass, double total)
    {
        return (pass + 1) / (total + 1) - pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;
        double added_profit;
        for (auto &c : classes)
        {
            total += (double)c[0] / c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--)
        {
            auto pq_item = pq.top();
            pq.pop();
            double added_profit = pq_item.first;
            auto c = pq_item.second;
            total += added_profit;
            pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
        }
        return total / classes.size();
    }
};

int main()
{
    vector<vector<int>> classes = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    int extraStudents = 4;
    Solution *solution = new Solution();
    cout << solution->maxAverageRatio(classes, extraStudents);
}