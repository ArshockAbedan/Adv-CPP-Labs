//============================================================================
// Name        : NumberOfProvinces.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : You are given an n x n matrix isConnected where isConnected[i][j] = 1
//               if the ith city and the jth city are directly connected,
//               and isConnected[i][j] = 0 otherwise. Return the total number of provinces.
//============================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[i][i] == 1)
            {
                count++;
                dfs(isConnected, i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> &M, int v)
    {
        if (M[v][v] == 0)
            return;
        for (int i = 0; i < M.size(); i++)
        {
            if (M[v][i] == 1)
            {
                M[v][i] = 0;
                dfs(M, i);
            }
        }
    }
};

int main()
{
    vector<vector<int>> arr_2d = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution *solution = new Solution();
    cout << solution->findCircleNum(arr_2d);
    return 0;
}