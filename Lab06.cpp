//============================================================================
// Name        : Lab06.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-06
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <cstring>
using namespace std;


// Base Class
class Cd
{
private:
    const char *performers;
    const char *label;
    int selections;
    double playtime;

public:
    // Default Constructor
    Cd()
    {
        this->performers = new char[8];
        this->performers = "Unknown";

        this->label = new char[8];
        this->label = "Unknown";

        this->selections = 0;
        this->playtime = 0.0;
    }
    // Parameterized Constructor
    Cd(const char *performers, const char *label, int selections, double playtime)
    {
        this->performers = new char[strlen(performers) + 1];
        this->performers = performers;

        this->label = new char[strlen(label) + 1];
        this->label = label;

        this->selections = selections;
        this->playtime = playtime;
    }
    virtual void Report()
    {
        cout << "Performer(s): " << performers << endl;
        cout << "Label: " << label << endl;
        cout << "Number of selections: " << selections << endl;
        cout << "Play time: " << playtime << endl;
    }
    ~Cd()
    {
        delete[] performers;
        performers = nullptr;
        delete[] label;
        label = nullptr;
    }
};

// Child class
class Classic : public Cd
{
private:
    const char *primaryWork;

public:
    // Default Constructor
    Classic()
    {
        this->primaryWork = new char[8];
        this->primaryWork = "Unknown";
    }
    // Parameterized Constructor
    Classic(const char *primaryWork, const char *performers, const char *label, int selections,
            double playtime) : Cd(performers, label, selections, playtime)
    {
        this->primaryWork = new char[strlen(primaryWork + 1)];
        this->primaryWork = primaryWork;
    }
    virtual void Report()
    {
        cout << "Primary work: " << primaryWork << endl;
        Cd::Report();
    }
    ~Classic()
    {
        delete[] primaryWork;
    }
};

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);

    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

    // Create a parent point and make it point to Cd object
    Cd *ptr = &c1;

    cout << "\nUsing object directly:\n";
    cout << "***************************" << endl;
    // Call Report() using Cd object
    c1.Report();

    // Call Report() using Classic object
    c2.Report();

    cout << "\nUsing type cd * pointer to objects:\n";
    cout << "***************************" << endl;

    // Call Report() using Cd type pointer created above
    ptr->Report();

    // Make ptr point to Classic Object
    ptr = &c2;

    // Call Report() using Cd type pointer containing Classic object address
    ptr->Report();

    return 0;
}
