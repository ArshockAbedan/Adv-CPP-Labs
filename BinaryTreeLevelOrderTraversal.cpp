//============================================================================
// Name        : BinaryTreeLevelOrderTraversal.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given the root of a binary tree,
//               return the level order traversal of its nodes' values.
//               (i.e., from left to right, level by level).
//============================================================================
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // return list of the level order traversal of its nodes' values. 
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> resultList;
        if (root == nullptr)
        {
            return resultList; // empty list
        }

        queue<TreeNode *> myQueue;
        myQueue.push(root);
        while (!myQueue.empty())
        {
            int size = myQueue.size();
            vector<int> currentLevel; // list of nodes in current level
            for (int i = 0; i < size; i++)
            {
                // After removing a node from queue
                // Its children should be added to queue.
                TreeNode *current = myQueue.front();
                myQueue.pop();
                currentLevel.push_back(current->val);
                if (current->left)
                {
                    myQueue.push(current->left);
                }
                if (current->right)
                {
                    myQueue.push(current->right);
                }
            }
            resultList.push_back(currentLevel);
        }
        return resultList;
    }

    void print_listOfList(vector<vector<int>> listOfList)
    {
        cout << "[";
        for (int i = 0; i < listOfList.size(); i++)
        {
            vector<int> list = listOfList.at(i);
            cout << "[";
            for (int j = 0; j < list.size(); j++)
            {
                cout << list.at(j);
                if (j != list.size()-1)
                {
                    cout << ",";
                }
            }
            cout << "]";
            if (i != listOfList.size()-1)
            {
                cout << ",";
            }
        }
        cout << "]";
    }
};

int main()
{
    //       3
    //     /   \
    //    9     20
    //         /  \
    //        15   7
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Solution *solution = new Solution();
    vector<vector<int>> listOfList = solution->levelOrder(node1);
    solution->print_listOfList(listOfList);
    return 0;
}