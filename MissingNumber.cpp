// Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int size = nums.size();
        int total = size * (size + 1) / 2;
        for (int i = 0; i < size; i++)
        {
            total -= nums[i];
        }
        return total;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> nums{0, 1, 2, 4, 6, 3, 7, 8};
    int missing = solution->missingNumber(nums);
    cout << " missing is " << missing;
    return 0;
}