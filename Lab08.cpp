//============================================================================
// Name        : Lab08.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-08
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <algorithm>
using namespace std;

// To overload the > operator to compare string lengths
int operator>(string str, string greater)
{

    return (str.length() > greater.length());
}

// define the generic max_numbers function.
template <typename T>
T max_numbers(T arr[], int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    // define 3 arrays
    double decimals[4] = {-3.4, 58.1, -76.4, 34.4};
    int integers[6] = {2, 3, 81, 1, 9, 22};
    string sequence[5] = {"Ontario", "Tech", "University", "Oshawa", "Canada"};

    // display for decimals
    double decimal;
    cout << "Array of decimals..." << endl;
    for_each(begin(decimals), end(decimals), [](double x)
             { cout << x << ", "; });
    decimal = max_numbers(decimals, 4);
    cout << "\nThe largest double: " << decimal << endl;

    // display for integres
    int integer;
    cout << "\n\nArray of integers..." << endl;
    for_each(begin(integers), end(integers), [](int x)
             { cout << x << ", "; });
    integer = max_numbers(integers, 6);
    cout << "\nThe largest integer: " << integer << endl;

    // display for characters
    string characters;
    cout << "\n\nArray of Strings..." << endl;
    for_each(begin(sequence), end(sequence), [](string x)
             { cout << x << ", "; });
    characters = max_numbers(sequence, 5);
    cout << "\nThe largest character sequence: " << characters << endl;

    return 0;
}
