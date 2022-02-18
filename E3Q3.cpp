//============================================================================
// Name        : E3Q3.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This exercise tests your knowledge of Dynamic Memory in C++.
//============================================================================
#include <iostream>
using namespace std;


void display(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}


// It increases the size of arr
int* resize(int* arr, int* size)
{
    int* temp = new int[*size + 1]; // Temp array with one more item

    // copy items from arr[] into temp[]
    for (int i = 0; i < *size; i++)
    {
        temp[i] = arr[i];
    }
    (*size)++; // increase the value of reference of size
    arr = temp;
    delete[] arr;
    return arr;
}

// Print even numbers in arr
void isEven(int* arr, int size)
{
    int even;
    int evenSize = 0; //new size for even array
    int* evenArray = new int[evenSize]; //create new dynamic array to store even numbers

    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) % 2 == 0) //if number is even
        {
            resize(evenArray, &evenSize); //size increases by 1 every time
            even = *(arr + i); 
            evenArray[evenSize - 1] = even;
        }
    }

    delete[] arr; // deallocate memory
    cout << endl;

    //display evenArray
    cout << "Array of even numbers: " << endl;
    display(evenArray, evenSize);

    delete[] evenArray;
}

int main()
{
    int number;
    int sizeOfArray; //size

    cout << "Enter the number of elements to store in an array: ";
    cin >> sizeOfArray;

    int* ptr = new int[sizeOfArray]; //create new dynamic array in Heap nad it's pointer in Stack

    cout << "Enter numbers to store in array: " << endl;

    for (int i = 0; i < sizeOfArray; i++) //user enters numbers for dynamic array
    {
        cin >> number;
        ptr[i] = number;
    }

    isEven(ptr, sizeOfArray); //print enter Even numbers.
    return 0;
}
