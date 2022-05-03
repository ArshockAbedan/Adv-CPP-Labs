//============================================================================
// Name        : Qualcomm-Q2.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Q4 mentioned in https://www.youtube.com/watch?v=rf317vRyifU
//============================================================================
#include <iostream>
#include <cstring>
using namespace std;

// changing pointer value through a function call
void func(int **p)
{
    int q = 10;
    *p = &q;
}

int main()
{
    int r = 20;
    int *p = &r;
    func(&p); // call by ref
    cout << *p << endl;
    return 0; 
}