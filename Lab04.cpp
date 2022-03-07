//============================================================================
// Name        : Lab04.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-04
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include<iostream>
#include<string>
#include "Lab04-Complex.h"
using namespace std;

// This function extracts real part i.e. 'a' from str (a,b)
double extractReal(string str) 
{
    return stod(str.substr(1, str.find(',')));
}

// This function extracts imaginary part i.e. 'b' from str (a,b)
double extractImaginary(string str)
{
    return stod(str.substr(str.find(',') + 1, str.find(',', 2) - 1)); // 2
}

// Oveloading '<<' operator for objects created based on Complex class
ostream& operator<<(ostream& output, Complex& complex)
{
    output << "(" << complex.getReal() << " , " << complex.getImaginary() << ")";
    return output;
}
int main() 
{
    double real, imaginary;
    string user_input;

    cout << "Enter First complex number in the form (a,b): ";
    getline(cin, user_input);

    real = extractReal(user_input);
    imaginary = extractImaginary(user_input);

    Complex first = Complex(real, imaginary);
    
    cout << "Enter Second complex number in the form (a,b): ";
    getline(cin, user_input);

    real = extractReal(user_input); 
    imaginary = extractImaginary(user_input);

    Complex second = Complex(real, imaginary);
    
    cout << "\n*******************************************" << endl;
    cout << "\tResults of Calculations" << endl;
    cout << "\n*******************************************" << endl;

    //Addition
    Complex result = first + second; 
    cout << first <<" + " << second << " = "<<result << endl<<endl;

    //Subtraction
    result = first - second;
    cout << first << " - " << second << " = " << result << endl << endl;

    //Multiplication
    result = first * second;
    cout << first << " * " << second << " = " << result << endl << endl;

    //Comparison
    if (first == second)
    {
        cout << first << " == " << second << endl << endl;
    }
    else
    {
        cout << first << " != " << second << endl << endl;
    }

    cout << "\n*******************************************" << endl;
} 
