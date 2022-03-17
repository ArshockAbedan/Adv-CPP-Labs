//============================================================================
// Name        : MostCommonWord.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given a string paragraph and a string array of the banned words banned,
//               return the most frequent word that is not banned.
//               It is guaranteed there is at least one word that is not banned,
//               and that the answer is unique.
//               The words in paragraph are case-insensitive and
//               the answer should be returned in lowercase.
//============================================================================
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, int> map; // map to store (distinct-word, freq)
        string word = "";               // to store each word
        int n = paragraph.length();
        int maxFreq = 0; // max global frequncy

        for (int i = 0; i < n; i++)
        {
            paragraph[i] = tolower(paragraph[i]);

            // if it's still a valid char, add it to others for makeing a word
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z')
            {
                word += paragraph[i];
            }
            else
            {
                // if we fetch a word and that word is not empty
                if (word != "")
                {
                    // if it was not added before add it to map
                    // if it exist, increase its frequency
                    map[word]++;
                }
                word = ""; // clear the word's buffer to strat over
            }
        }

        // try to avoid missing last word
        if (paragraph[n - 1] >= 'a' && paragraph[n - 1] <= 'z')
        {
            map[word]++;
        }

        // From now, we use word to return the result;
        word = "";

        // remove banned words
        for (string str : banned)
        {
            map.erase(str);
        }

        // finding the max frequency and its crossponding word
        for (auto it : map)
        {
            if (it.second > maxFreq)
            {
                maxFreq = it.second;
                word = it.first;
            }
        }

        return word;
    }
};

int main()
{
    string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = {"hit"};
    Solution *solution = new Solution();
    cout << solution->mostCommonWord(str, banned);
}