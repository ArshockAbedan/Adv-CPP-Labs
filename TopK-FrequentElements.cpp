//============================================================================
// Name        : TopK-FrequentElements.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an integer array nums and an integer k, 
//               return the k most frequent elements. You may return the answer in any order.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        if (nums.size() == 0)
        {
            return {};
        }

        // vector of size k+1 to store elements
        vector<int> top(k + 1);

        // array to keep track of frequency
        unordered_map<int, int> freq;

        for (int m = 0; m < nums.size(); m++)
        {
            // increase the frequency fr each item
            freq[nums[m]]++;

            // store that element in the top vector
            top[k] = nums[m];

            // search for same element in top vector
            auto it = find(top.begin(), top.end() - 1, nums[m]);

            // iterate from (position of element) -1 to zero
            // current element is in top[i + 1]
            for (int i = distance(top.begin(), it) - 1; i >= 0; i--)
            {
                
                // compare frequncy and swao if it is higher 
                if (freq[top[i]] < freq[top[i + 1]])
                {
                    swap(top[i], top[i + 1]);
                }
                // if frequnecy is the same, swap when next element in reverse direction is higher
                else if ((freq[top[i]] == freq[top[i + 1]]) && (top[i] > top[i + 1]))
                {
                    swap(top[i], top[i + 1]);
                }
                else
                {
                    break;
                }
            }

            // push elements in top to the result vector
            for (int j = 0; j < k && top[j] != 0; j++)
            {
                result.push_back(top[j]);
            }
        }

        return result;
    }
};

// Driver program to test above function
int main()
{
    int k = 4;
    vector<int> arr = {5, 2, 1, 3, 2};
    Solution *solution = new Solution();
    vector<int> res = solution->topKFrequent(arr, k);
    cout << "[" << res[0];
    for (int i = 1; i < res.size(); i++)
    {
        cout << ", " << res[i];
    }
    cout << "]";
    return 0;
}