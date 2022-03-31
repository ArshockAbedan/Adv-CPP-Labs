//============================================================================
// Name        : CountOfSmallerNumsAfterSelf.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int *bit, len;
    void updateBit(int n)
    {
        while (n < len)
        {
            // Add 1 to current node of bit
            bit[n]++;
            // Update index to that of parent in update
            n += n & (-n);
        }
    }
    int getValueFromBit(int n)
    {
        int res = 0;
        while (n > 0)
        {
            // Add current element of bit to sum
            res += bit[n];
            // Move index to parent node
            n -= n & (-n);
        }
        return res;
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        // support variables
        int minV = INT_MAX, maxV = INT_MIN;
        len = nums.size();
        vector<int> res(len);
        // getting the extremes of the input range
        for (int n : nums)
        {
            minV = min(minV, n);
            maxV = max(maxV, n);
        }
        len = maxV - --minV + 1;
        // edge case - all elements of nums are equal
        if (len == 2)
            return res;
        // preparing the bit tree
        bit = new int[len];
        fill(bit, bit + len, 0);
        // filling res from right to left
        for (int i = nums.size() - 1, n; i >= 0; i--)
        {
            n = nums[i] - minV;
            // getting the frequency of all the elements up to n
            res[i] = getValueFromBit(n - 1);
            // updating the tree
            updateBit(n);
        }
        return res;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = solution->countSmaller(nums);
    cout << "[" << res[0];
    for (int i = 1; i < res.size(); i++)
    {
        cout << ", " << res[i];
    }
    cout << "]";
}