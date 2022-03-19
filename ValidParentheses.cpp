//============================================================================
// Name        : ValidParentheses.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given a string s containing just the characters 
//               '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//               An input string is valid if:
//               1- Open brackets must be closed by the same type of brackets.
//               2- Open brackets must be closed in the correct order.
//============================================================================
#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                stack.push(c);
            }else if (c == ')' && !stack.empty() && stack.top() == '('){
                stack.pop();
            }else if (c == '}' && !stack.empty() && stack.top() == '{'){
                stack.pop();
            }else if (c == ']' && !stack.empty() && stack.top() == '['){
                stack.pop();
            }else{
                return false;
            }
        }

        return stack.empty();
    }
};

int main()
{

    string s = "()[]{}";
    Solution *solution = new Solution();
    bool result = solution->isValid(s);
    if(result){
        cout << "True";
    }else{
        cout << "False";
    }
    return 0;
}
