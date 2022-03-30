//============================================================================
// Name        : SlowestKey.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/slowest-key/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int n = releaseTimes.size();
        char res = 'a';
        int longestDuration = 0;
        int pressedTime;
        int duration;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                pressedTime = 0;
            }
            else
            {
                pressedTime = releaseTimes[i - 1];
            }
            duration = releaseTimes[i] - pressedTime;
            if (duration == longestDuration)
            {
                res = max(res, keysPressed[i]); // lexicographically largest key
            }
            else if (duration > longestDuration)
            {
                res = keysPressed[i];
                longestDuration = duration;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> releaseTimes = {12, 23, 36, 46, 62};
    string keysPressed = "spuda";
    Solution *solution = new Solution();
    cout << solution->slowestKey(releaseTimes, keysPressed);
    return 0;
}