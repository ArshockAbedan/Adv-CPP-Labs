//============================================================================
// Name        : ReverseWordsInAString.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given an input string s, reverse the order of the words.
//============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result; // final string
        string word = ""; // used to tokanize each word
        stack<string> myStack; // FIFO
        for(int i=0; i<s.length(); i++){
            if((s[i]==' ') && (word.length() == 0)){
                continue; // ignore spaces in beginning 
            }
            if(s[i] == ' '){
                myStack.push(word); // store each word in stack
                word = "";
            }else if (i == s.length()-1){
                 // last word if there is no space at the end
                 word += s[i];
                 myStack.push(word); 
                 word = "";
            }else{
                // regular chars
                word += s[i];
            }
        }
        
        while(!myStack.empty()){
            result += myStack.top();
            if(myStack.size() != 1){
                result += " "; // there is no need for extra space at the end.
            }
            myStack.pop();
        }
        
        return result;
        
    }
};

int main(){

    string input = "the sky is blue";
    Solution *solution = new Solution();
    cout << solution->reverseWords(input);
    return 0;
}