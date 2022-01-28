//============================================================================
// Name        : 1-Q1.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This exercise tests your knowledge of strings in C++.
//============================================================================
#include <iostream>
#include <vector>
#include <set>
using namespace std;


void displayOutput(vector<int> numbers){
    cout << "Arrays elements after removing duplicates ..." << endl;
    for(int i=0; i < numbers.size(); i++){
        cout << numbers[i] << "\t";
    }
}

int main()
{
    const int MAX_NUM = 5;
    int entered_number = -1;
    vector<int> numbers;
    set<int> s;
    vector<int> distinct_numbers;

    cout << " Enter " << MAX_NUM << " numbers into array...5 " << endl;
    for (int i = 0; i < MAX_NUM; i++)
    {
        cout << "element " << i << ": ";
        cin >> entered_number;
        if (entered_number < 0)
        {
            cout << "Please enter a positive number." << endl;
            i--;
        }
        else
        {
            numbers.push_back(entered_number);
            s.insert(numbers[i]);
        }
    }

    if (s.size() == numbers.size())
    {
        cout << "Please enter at least one duplicate number.";
    }
    else if (s.size() == 1)
    {
        cout << "All numbers can be the same.";
    }
    else
    {
        distinct_numbers.assign( s.begin(), s.end());
        displayOutput(distinct_numbers);
    }

    return 0;
}
