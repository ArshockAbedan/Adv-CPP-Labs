//============================================================================
// Name        : Lab05.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-05
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <vector>
using namespace std;

// define parent class
class Student
{
protected:
    vector<string> levels; // this is vector of strings
public:
    // default constructor
    Student()
    {
    }

    void addToVector(string level)
    {
        levels.push_back(level);
    }

    vector<string> &getStudyLevels()
    {
        return this->levels;
    }
};


// Child class
class Undergraduate : public Student
{
public:
    Undergraduate()
    {
    }
};

// Child class
class Graduate : public Student
{
public:
    Graduate()
    {
    }
};

void assignStudents(vector<Student *> &v)
{
    string level;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a study level: ";
        cin >> level;

        if (level == "Undergraduate")
        {
            Undergraduate *ug = new Undergraduate();
            v.push_back(ug);
        }
        else
        {
            Graduate *graduate = new Graduate();
            v.push_back(graduate);
        }
        // add level(user entered string) to the vector (as the first element) of current object.
        v[i]->addToVector(level); 
    }

    int ug_count = 0, graduate_count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        // v is vector of students
        // v[i]->getStudyLevels() is vector of strings
        // v[i]->getStudyLevels()[0] is the first string.
        if (v[i]->getStudyLevels()[0] == "Undergraduate")
        {
            ug_count++;
        }
        else
        {
            // if it is graduate
            graduate_count++;
        }
    }
    cout << "Undergraduates: " << ug_count << endl;
    cout << "Graduates: " << graduate_count << endl;
}
int main()
{
    vector<Student *> v; //  this is vector of Students(pointers)
    assignStudents(v);
    return 0;
}