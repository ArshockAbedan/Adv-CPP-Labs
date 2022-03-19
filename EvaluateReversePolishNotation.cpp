//============================================================================
// Name        : CopyListwithRandomPointer.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//               Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
//               It is guaranteed that the given RPN expression is always valid.
//============================================================================
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    private:
    bool isOperator(string s){
        return ( s == "+" or s == "-" or s == "*" or s == "/");
    }

    int operate( int a , int b, string op){
        if (op == "+") return a+b;
        if (op == "-") return a-b;
        if (op == "*") return a*b;
        return a/b; 
    }
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stack;
        int firstOperand, secondOperand;
        for(auto token : tokens){
            if(isOperator(token)){
                secondOperand = stack.top(); stack.pop(); 
                firstOperand = stack.top(); stack.pop();
                stack.push(operate(firstOperand, secondOperand, token));
            }else{
                stack.push(stoi(token));
            }
        }
        return stack.top();
    }
};

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution *solution = new Solution();
    cout << solution->evalRPN(tokens);
    return 0;
}