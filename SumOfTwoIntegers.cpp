//============================================================================
// Name        : SumOfTwoIntegers.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given two integers a and b,
//               return the sum of the two integers without using the operators + and -.
//============================================================================
#include <iostream>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        if (b > 0)
        {
            while (b > 0)
            {
                a++;
                b--;
            }
        }
        else if (b < 0)
        {
            while (b < 0)
            {
                a--;
                b++;
            }
        }
        return a;
    }
};

int main()
{
    Solution *solution = new Solution();
    /* initialize random seed: */
    srand(time(NULL));
    // generate two numbers between -1000 and 1000
    int firstRandNum = (rand() % 2000) - 1000;
    int secondRandNum = (rand() % 2000) - 1000;
    int sum = solution->getSum(firstRandNum, secondRandNum);
    cout << "Sum of " << firstRandNum << " and " << secondRandNum << " is " << sum;
    return 0;
}