//============================================================================
// Name        : QuickSort.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : QuickSort implementation
//============================================================================
#include <iostream>
using namespace std;


int partition(int arr[], int low, int high){
    
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high)
    }
}

int main()
{
    int arr[] = {12, 15, 24, 1, 7, 18, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array:" << endl;
    printArray(arr);
    return 0;
}