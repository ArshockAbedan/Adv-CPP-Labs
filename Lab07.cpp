//============================================================================
// Name        : Lab07.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-07
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <array>

using namespace std;

const int SIZE = 10; // Global size

// is the userinput exist in arr?
bool isDuplicate(array<int, SIZE> arr, int userinput)
{
    bool flag = false;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == userinput)
        {
            flag = true;
        }
    }
    return flag;
}

int main()
{

    array<int, SIZE> arr{};

    int Userinput;
    int i = 0;
    int newsize = 0;

    cout << "enter an integer between 10 and 100: " << endl;

    while (i < arr.size())
    {

        cout << "Enter a number: ";
        cin >> Userinput;

        if (Userinput >= 10 & Userinput <= 100) // if the userinput is valid
        {
            if (isDuplicate(arr, Userinput)) // if the userinput is duplicated.
            {
                cout << "Duplicate number." << endl;
                cout << "\n"
                     << endl;
            }
            else
            {
                arr[newsize++] = Userinput; // newSize will increase when Userinput is not duplicated.
            }

            i++;
        }
        else
        {
            // if the userinput is NOT valid.
            cout << "\ninvalid number. please enter a number between 10 and 100: " << endl;
        }
    }

    // Print non-duplicate numbers
    cout << "The nonduplicate values are: " << endl;

    for (int j = 0; j < newsize; j++) // newsize contains the limit
    {

        cout << arr[j] << " ";
    }

    return 0;
}