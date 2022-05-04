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
        vector<vector<string>> res; // output
        // Helper map ( Key: unique sorted version of each angram, Value: list of all Anagrams)
        unordered_map<string, vector<string>> map; 
        string originalStr;
        vector<string> tempVector;
        if (strs.size() < 1)
        {
            return res;
        }

        for (string str : strs)
        {
            originalStr = str; // after sort, the original string should be kept unchanged.
            // if we sort each of all anagrams, the result would be the same
            sort(str.begin(), str.end()); 
            // and we can use this sorted str as a key for map
            if (map.count(str) > 0)
            {
                map[str].push_back(originalStr);
            }
            else
            {
                // if this sorted key is not there, lets create a new one.
                tempVector.clear();
                tempVector.push_back(originalStr);
                map.insert({str, tempVector});
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