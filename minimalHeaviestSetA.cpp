#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> minimalHeaviestSetA(vector<int> arr)
    {

        int n = arr.size();
        multimap<int, vector<int>> map;
        int sumGlobal;
        int maxGlobal = INT_MIN;
        sort(arr.begin(), arr.end(), greater<>());

        for (int i = 0; i < n; i++)
        {
            sumGlobal += arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            vector<int> temp;
            int j = i;
            int privousItem = arr[i];
            while (((currSum < sumGlobal - currSum) && (j < n)) || (arr[j] == privousItem))
            {
                temp.push_back(arr[j]);
                currSum += arr[j];
                privousItem = arr[j];
                j++;
            }
            map.insert({currSum, temp});
            if (currSum > maxGlobal)
            {
                maxGlobal = currSum;
            }
        }

        return map.find(maxGlobal)->second;
    }
};

int main()
{
    vector<int> arr = {6, 5, 5, 5, 3, 2, 4, 1, 2};
    int k = 5;
    Solution *solution = new Solution();
    vector<int> List = solution->minimalHeaviestSetA(arr);
    cout << "[" << List[0];
    for (int i = 1; i < List.size(); i++)
    {
        cout << ", " << List[i];
    }
    cout << "]";
    return 0;
}