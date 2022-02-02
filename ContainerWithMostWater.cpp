#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        int temp_area = 0;
        int distance = 0;
        while( left < right){
            distance = right - left;
            temp_area = std::min(height[left], height[right]) * distance; 
            if (temp_area > max_area  ){
                max_area = temp_area;
            }
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};


int main()
{
    Solution *solution = new Solution();
    vector<int> vec{1,8,6,2,5,4,8,3,7};
    int max_area = solution->maxArea(vec);
    cout << max_area;
}