//============================================================================
// Name        : ReadFile.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : read a simple file
//============================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    // read a file
    string filePath = "C:/Users/100795022/Desktop/TA/BlueCat/top-1m.csv";
    ifstream file(filePath);
    string line;       // each line in the file
    string domain;     // each domain in the line
    string firstLable; // first part of each domian
    vector<string> allFirstLables;
    set<string> uniqueFirstLables;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            domain = line.substr(line.find(',') + 1);
            firstLable = domain.substr(0, domain.find("."));
            allFirstLables.push_back(firstLable);
            uniqueFirstLables.insert(firstLable);
        }
        cout << "There are total of " << allFirstLables.size() << " domains.\n";
        cout << uniqueFirstLables.size() << " of them are unique domains.";
    }
    else
    {
        cout << "File can not be opended!";
    }
    return 0;
}