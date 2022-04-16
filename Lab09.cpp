//============================================================================
// Name        : Lab09.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-09
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Conversion
{
private:
    char *char_number;

public:
    Conversion(const char *number)
    {
        int size = strlen(number);
        char_number = new char[size + 1];

        // Copy number into char_number
        // in order to make it's value availbe for other methods inside the class.
        for (int i = 0; i < size; i++)
        {
            char_number[i] = number[i];
        }
        char_number[size] = 0;
    }

    void convert()
    {
        int number = stoi(char_number);
        cout << "Binary of " << number << " is: ";
        DecimalToBinary(number);
    }
    void DecimalToBinary(int n)
    {
        // It's a recursive function,
        // The base Status should be defined.
        if (n == 0)
        {
            return;
        }
        DecimalToBinary(n / 2); // call itself recursively with value / 2.
        cout << n % 2;          // The remainder would be either 1 or 0.
    }
    // Destructor
    ~Conversion()
    {
        delete[] char_number;  // first delete tails
        char_number = nullptr; // then eliminate head
    }
};

int main()
{
    char number[10] = {};
    cout << "Enter an integer to convert to binary: ";
    cin >> number;

    Conversion conversion = Conversion(number);
    conversion.convert();

    cout << endl;
    return 0;
}
