//============================================================================
// Name        : groupAnagrams.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/group-anagrams/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        int n = strs.size();
        if (n < 1)
        {
            return res;
        }

        unordered_map<string, vector<string>> map;
        for (string str : strs)
        {
            string originalStr = str;
            sort(str.begin(), str.end());
            if (map.count(str) > 0)
            {
                map[str].push_back(originalStr);
            }
            else
            {
                vector<string> temp;
                temp.push_back(originalStr);
                map.insert({str, temp});
            }
        }

        for (auto const &item : map)
        {
            res.push_back(item.second);
        }

        return res;
    }
};

int main()
{
    vector<string> stringList = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution *solution = new Solution();
    vector<vector<string>> results = solution->groupAnagrams(stringList);
    for (vector<string> res : results)
    {
        cout << "[" << res[0];
        for (int i = 1; i < res.size(); i++)
        {
            cout << ", " << res[i];
        }
        cout << "]" << endl;
    }
    return 0;
}