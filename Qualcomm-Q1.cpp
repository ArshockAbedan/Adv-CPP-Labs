//============================================================================
// Name        : Qualcomm-Q1.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Q1 mentioned in https://www.youtube.com/watch?v=rf317vRyifU
//============================================================================
#include <iostream>
using namespace std;

struct Node
{
    int a;
    int b;
};

int main()
{
    struct Node *ptr = NULL; // It is definition of a null pointer.
    cout << ptr << endl;     // output is 0
    cout << true << endl;    // output is 1
    if (ptr && ptr->a)
    { // becuase insdie if condition is 0 and zero means false in c++,
      // these line inside if will not be run.
        ptr->a = 2;
        cout << ptr << ptr->a << endl;
    }
    cout << "reached outside if";
    return 0;
}