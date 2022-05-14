//============================================================================
// Name        : MicrosoftInterview.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Microsoft Interview code
//============================================================================
#include <iostream>
#include <string>

using namespace std;

enum State
{
    q0,
    q1,
    q2,
    qd
};

class StateMachine
{
private:
    State currentState;
    int sign, result;

    // transition to state Q1
    void toStateQ1(char &ch)
    {
        sign = ch == '-' ? -1 : 1;
        currentState = q1;
    }

    // transition to state Q2
    void toStateQ2(int digit)
    {
        currentState = q2;
        appendDigit(digit);
    }

    // transition to Dead State
    void toStateQd()
    {
        currentState = qd;
    }

    // append digit to result, if out of range return handled value
    void appendDigit(int digit)
    {
        if ((digit > INT_MAX / 10) || (digit == INT_MAX && digit > INT_MAX % 10))
        {
            if (sign == 1)
            {
                // if sign is 1, round the resut to maximum of int
                result = INT_MAX;
            }
            else
            {
                // if sign is -1, round the result to minimum of int
                result = INT_MIN;
                sign = 1;
            }
            // when it is out of range i.e in both side, a dead state is reached
            toStateQd();
        }
        else
        {
            // when it is not out of range, append current digit to result
            result = result * 10 + digit;
        }
    }

public:
    StateMachine()
    {
        currentState = q0;
        sign = 1;
        result = 0;
    }

    // get current state
    State getCurrState()
    {
        return currentState;
    }

    // change current state based of input (current character)
    void transition(char &c)
    {
        if (currentState == q0)
        {
            // begining or some withspace is skipped already.
            if (c == ' ')
            {
                // current chracter is whitespace, so we stay in the same state.
                return;
            }
            else if (isdigit(c))
            {
                // current character is a digit
                toStateQ2(c - '0');
            }
            else if (c == '-' || c == '+')
            {
                // current character is a sign
                toStateQ1(c);
            }
            else
            {
                // current character is not digit/sign/space
                // a dead state is reached
                toStateQd();
            }
        }
        else if (currentState == q1 || currentState == q2)
        {
            // previous characte was either a sign or a digit
            if (isdigit(c))
            {
                // current state is a digit
                toStateQ2(c - '0');
            }
            else
            {
                // current character is not a digit
                // a dead state is reached.
                toStateQd();
            }
        }
    }

    // eturn final result along with its sign
    int getInteger()
    {
        return sign * result;
    }
};

class Solution
{
public:
    int myAtoI(string word)
    {
        StateMachine Q;
        for (int i = 0; i < word.length() && Q.getCurrState() != qd; i++)
        {
            Q.transition(word[i]);
        }

        return Q.getInteger();
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << solution->myAtoI("12 2") << endl;
    cout << solution->myAtoI("   -42");
}