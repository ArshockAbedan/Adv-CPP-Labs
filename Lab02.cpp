//============================================================================
// Name        : Lab02.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-02
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class WordCounter
{
private:
    string word;
    int count;

public:
    WordCounter(string word, int count)
    {
        this->word = word;
        this->count = count;
    }
    string getWord()
    {
        return word;
    }
    int getCount()
    {
        return count;
    }
    void setWord(string word)
    {
        this->word = word;
    }
    void setCount(int count)
    {
        this->count = count;
    }
};

// It checks whether "v" contains "word" or not.
bool isFound(vector<WordCounter> &v, string word)
{
    bool flag = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].getWord() == word)
        {
            flag = true;
        }
    }
    return flag;
}

// It increases occurance (count) of "word" in "v" vector  
void incrementWordCount(vector<WordCounter> &v, string word)
{

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].getWord() == word)
        {
            v[i].setCount(v[i].getCount() + 1);
        }
    }
}

// print the output.
void printReport(vector<WordCounter> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].getWord() << ": " << v[i].getCount() << endl;
    }
}

int main()
{
    string word;
    vector<WordCounter> wordCounter;

    ifstream file;
    file.open("data.txt");

    while (file >> word)
    {
        if (isFound(wordCounter, word))
        {
            // it means "word" is duplicated.
            incrementWordCount(wordCounter, word);
        }
        else
        {
            // it means "word" is a new one.
            WordCounter counter = WordCounter(word, 1);
            wordCounter.push_back(counter);
        }
    }

    file.close();

    printReport(wordCounter);

    return 0;
}
