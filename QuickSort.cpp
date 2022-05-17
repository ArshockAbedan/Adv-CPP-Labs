//============================================================================
// Name        : QuickSort.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : QuickSort implementation
//============================================================================
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
}


/* The main function to implement QuickSort
arr[] --> Array to be sorted
low --> starting index
high --> end index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // seperately sort items befor partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high)
    }
}

// function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; int i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {12, 15, 24, 1, 7, 18, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array:" << endl;
    printArray(arr, n);
    return 0;
}