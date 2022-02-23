//============================================================================
// Name        : PermutationSequence.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//               Given n and k, return the kth permutation sequence.
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> facts, digits;

public:
    void solve(string &ans, int n, int k)
    {
        if (n == 1)
        { // use last digit
            ans += to_string(digits.back());
            return;
        }

        // define num of blocks to skip
        // size of each block is n-1! or facts[n-1]
        int index = k / facts[n - 1];

        if (k % facts[n - 1] == 0)
        { // we need to convert 1 based to 0 based.
            index--;
        }

        ans += to_string(digits[index]);      // add new digits
        digits.erase(digits.begin() + index); // remove used digit

        k -= facts[n - 1] * index; // decrease k value base on skiped block
        solve(ans, n - 1, k);
    }
    string getPermutation(int n, int k)
    {
        if (n == 1)
        {
            return "1";
        }

        string ans = ""; // saving result

        // store all factorials from 0 to n
        facts.push_back(1); // 0!
        int f = 1;
        for (int i = 1; i < n; i++)
        {
            f *= i;
            facts.push_back(f);
            digits.push_back(i); // store all digits in one array
        }
        digits.push_back(n);

        solve(ans, n, k);
        return ans;
    }
};

int main()
{
    Solution *solution = new Solution();

    // initialize random seed
    srand(time(NULL));
    // pick a random n between 1 to 9
    int n = rand() % 9 + 1;
    cout << "n = " << n << endl;
    int k = -1;
    int f = 1; // a variable to compute n!
    if (n == 1)
    {
        k = 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            f *= i;
        }
    }
    // pick a random n between 1 to n!
    k = rand() % f + 1;

    cout << "k = " << k << endl;
    cout << k << "th permutation is " << solution->getPermutation(n, k);
    return 0;
}