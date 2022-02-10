//============================================================================
// Name        : Lab01.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-01
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// It checks whether "v" contains "word" or not.
bool isFound(vector<string> v, string word)
{
    bool flag = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == word)
        {
            flag = true;
        }
    }
    return flag;
}

// print the output.
void printReport(vector<string> words, vector<int> counts)
{
    for (int i = 0; i < counts.size(); i++)
    {
        cout << words[i] << ": " << counts[i] << endl;
    }
}

// It returns the index of duplicated "word" in the "words" collection.
int fountIndexAtWord(vector<string> words, string word)
{
    int index;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == word)
        {
            index = i;
        }
    }
    return index;
}

int main()
{
    string word;
    vector<string> words;
    vector<int> counts;

    // read file
    ifstream file;
    file.open("data.txt");
    while (file >> word)
    {
        if (isFound(words, word))
        { // it means "word" is duplicated.
            counts[fountIndexAtWord(words, word)]++;
        }
        else
        { // it means "word" is a new one.
            words.push_back(word);
            counts.push_back(1);
        }
    }

    file.close();
    return 0;
}