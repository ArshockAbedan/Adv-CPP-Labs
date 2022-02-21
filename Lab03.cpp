//============================================================================
// Name        : Lab03.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-03
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bits
{
private:
    string sequence;
    string packet;

public:
    Bits()
    {
        sequence = "";
        packet = "";
    }

    void setsequence(string sequence)
    {
        this->sequence = sequence;
    }

    string getsequence()
    {
        return sequence;
    }

    void setpacket(string packet)
    {
        this->packet = packet;
    }

    string getpacket()
    {
        return packet;
    }

    void toString()
    {

        cout << packet << ": " << sequence << endl;
    };

    bool isEmpty()
    {
        bool flag = false;

        if (sequence.empty() || packet.empty())
        {
            flag = true;
        }
        return flag;
    }
};

// It search for user_sequence in word
// if it can find it; it create an object with proper packet and sequence
Bits getBitsObject(string word, string user_sequence)
{
    Bits bitObj; // create an empty object based on Bits class(Blue print).
    string packet;
    string sequence;
    packet = word.substr(0, word.find(","));
    sequence = word.substr(word.find(",") + 1);
    if (word.find(user_sequence) != string::npos)
    {
        // If it finds the user's bit in the line, it creates an object with proper values
        bitObj.setpacket(packet);
        bitObj.setsequence(sequence);
    }
    return bitObj;
}

// It increases the size of arr
Bits *resize(Bits *arr, int *size)
{

    Bits *resize_arr = new Bits[*size + 1]; // create a resize_arr array with one more item
    for (int i = 0; i < *size; i++)
    {
        resize_arr[i] = arr[i];
    }
    delete[] arr; // deallocate unnecessary memory
    arr = 0;
    arr = resize_arr;
    resize_arr = 0;
    (*size)++; // increase the value of reference of size pointer
    return arr;
}

// print items of arr[]
void display(Bits *arr, int size)
{
    cout << endl;
    cout << "******************** Bit Sequence Found ********************" << endl;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i].toString();
    }
    cout << endl;
    cout << "Total Occurrences: " << size << endl;
    cout << endl;
    cout << "**************************************************************" << endl;
}

int main()
{

    int size = 0;
    Bits *arr = new Bits[size]; // arrays created in heap
    string user_sequence;
    string line;

    // get user's bit
    cout << "Enter a bit sequence: ";
    cin >> user_sequence;

    // read the file
    ifstream file("bits.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            // create an object for each line. If line contains user_sequence, bitObj would not be empty.
            Bits bitObj = getBitsObject(line, user_sequence);
            if (!bitObj.isEmpty())
            {
                arr = resize(arr, &size); // increase size of arr
                arr[size - 1] = bitObj;   // Fill in the empty item with created bit Object.
            }
        }
        file.close();
        // print the expected output.
        display(arr, size);
    }
    else
    {
        cout << "Unable to open file";
    }
    return 0;
}
