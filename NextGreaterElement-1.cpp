//============================================================================
// Name        : CopyListwithRandomPointer.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : The next greater element of some element x in an array is
//               the first greater element that is to the right of x in the same array.
//               You are given two distinct 0-indexed integer arrays nums1 and nums2,
//               where nums1 is a subset of nums2. For each 0 <= i < nums1.length,
//               find the index j such that nums1[i] == nums2[j] and determine
//               the next greater element of nums2[j] in nums2.
//               If there is no next greater element, then the answer for this query is -1.
//               Return an array ans of length nums1.length such that ans[i] is the
//               next greater element of nums2.
//============================================================================
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        stack<int> stack;
        unordered_map<int, int> map;

        for (int i = 0; i < nums2.size(); i++)
        {
            while (stack.size() > 0 && nums2[i] > stack.top())
            {
                map.insert(pair<int, int>(stack.top(), nums2[i]));
                stack.pop();
            }
            stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            int val = map[nums1[i]];
            if (val == 0)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(val);
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution *solution = new Solution();
    vector<int> result = solution->nextGreaterElement(nums1, nums2);
    cout << "[" << result[0];
    for (int i = 1; i < result.size(); i++)
    {
        cout << ", " << result[i];
    }
    cout << "]";
    return 0;
}