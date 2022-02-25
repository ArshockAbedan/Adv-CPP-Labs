//============================================================================
// Name        : SDEInterviewCodingExample.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Having 2d array of robot's postion,
//               check whether next state is a valid state or not.
//               robot can move 1 index to left and right.
//============================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidPath(int numRobots, vector<vector<int>> arr_2d)
    {
        int n_rows = arr_2d.size();
        int n_cols = arr_2d[0].size();

        for (int i = 0; i < n_rows; i++)
        {
            int robotsInOneRow = 0;
            for (int j = 0; j < n_cols; j++)
            {
                if (arr_2d[i][j] == 1)
                {
                    robotsInOneRow++;
                }
            }
            if (robotsInOneRow != numRobots)
            {
                return false;
            }
        }

        for (int i = 0; i < n_rows; i++)
        {
            for (int j = 0; j < n_cols; j++)
            {
                if (arr_2d[i][j] == 1)
                {
                    if (j == 0) // First item
                    {
                        if (!((arr_2d[i][j + 1] == 1) || (arr_2d[i][n_cols - 1] == 1)))
                        {
                            return false;
                        }
                    }
                    else if (j == n_cols - 1) // last item
                    {
                        if (!((arr_2d[i][n_cols - 2] == 1) || (arr_2d[i][0] == 1)))
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (!((arr_2d[i][j - 1] == 1) || (arr_2d[i][j + 1] == 1)))
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution *solution = new Solution();
    int numRobots = 2;
    // int arr_2d[2][4] = {{1, 0, 0, 1}, {0, 1, 1, 0}};
    vector<vector<int>> arr_2d{{1, 0, 0, 0, 1}, {1, 0, 1, 0, 0}};
    bool isValid = solution->isValidPath(numRobots, arr_2d);
    cout << isValid;
    return 0;
}