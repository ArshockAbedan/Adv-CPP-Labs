//============================================================================
// Name        : Word_Ladder_2.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/word-ladder-ii/
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // unweighted undirected graph
        // build a directed graph that begins from beginWord and terminates at endWord
        // instead of copying words around, we will use indices into the original word list as handles

        int beginIndex = -1;
        int endIndex = -1;

        // get index of beginWord and endword if possible
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (wordList[i] == beginWord)
            {
                beginIndex = i;
            }
            else if (wordList[i] == endWord)
            {
                endIndex = i;
            }
        }
        // if endWord is not present, unsolvable, return empty list
        if (endIndex == -1)
        {
            return {};
        }
        // if beginWord is not present, add to list and save index
        if (beginIndex == -1)
        {
            wordList.push_back(beginWord);
            beginIndex = int(wordList.size()) - 1;
        }

        // edges[i] contains the adjacency list for word i
        vector<vector<int>> edges(wordList.size());

        // we uses a vector of bools to mark each word as visited
        vector<bool> seen(wordList.size(), false);
        // we will do a level traversal, this is our first level
        vector<int> level = {beginIndex};
        seen[beginIndex] = true;

        // at any point during the traversal, we only want examine edges between words at the current level and words that are not at the current level or above it in our final tree
        // this is not the same as "we only want edges between the current level and words that have not been queued"
        // the problem with the above statement is that while we process the current level, we may queue nodes that should be considered children as another node in the current level
        // we only want to remove queued words from consideration after we have fully processed the level

        // word indices will contain only indices of words that have not been enqueud by a node above the current level
        // the reason for using this is to skip over words that no longer matter
        vector<int> word_indices;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (i != beginIndex)
            {
                word_indices.push_back(i);
            }
        }

        // do the level traversal until we run out of nodes or we found the target at some level
        while (!level.empty() && !seen[endIndex])
        {
            vector<int> next_level;
            // process current level
            for (int i : level)
            {
                // check if the current word has any neighbors in word indices
                for (int j : word_indices)
                {
                    if (adjacent(wordList[i], wordList[j]))
                    {
                        // this is a downward edge in our final tree
                        edges[i].push_back(j);
                        // if not already queued, enqueue it to the next level
                        if (!seen[j])
                        {
                            next_level.push_back(j);
                            seen[j] = true;
                        }
                    }
                }
            }

            // all word indices that were not enqueued will go into the next set of indices
            vector<int> next_word_indices;
            for (int j : word_indices)
            {
                if (!seen[j])
                {
                    next_word_indices.push_back(j);
                }
            }

            // set next level and next set of indices
            swap(level, next_level);
            swap(word_indices, next_word_indices);
        }

        // do DFS with backtracking path
        vector<vector<string>> output;
        vector<string> path;
        dfs(edges, wordList, output, path, beginIndex, endIndex);
        return output;
    }
    void dfs(vector<vector<int>> &edges, vector<string> &wordList, vector<vector<string>> &output, vector<string> &path, int currentIndex, int endIndex)
    {
        path.push_back(wordList[currentIndex]);
        if (currentIndex == endIndex)
        {
            output.push_back(path);
        }
        else
        {
            for (int child : edges[currentIndex])
            {
                dfs(edges, wordList, output, path, child, endIndex);
            }
        }
        path.pop_back();
    }

    /*
    all words are unique
    words are adjacent if they differ by one character
    words are adjacent only if they are the same length
    */
    bool adjacent(string &a, string &b)
    {
        if (a.size() != b.size())
        {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
            {
                diff++;
                if (diff > 1)
                {
                    return false;
                }
            }
        }
        return diff == 1;
    }
};

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";
    Solution *solution = new Solution();
    vector<vector<string>> result = solution->findLadders(beginWord, endWord, wordList);
    for (vector<string> res : result)
    {
        cout << "[" << res[0];
        for (int i = 1; i < res.size(); i++)
        {
            cout << ", " << res[i];
        }
        cout << "]" << endl;
    }
    return 0;
}