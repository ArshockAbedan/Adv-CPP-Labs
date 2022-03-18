//============================================================================
// Name        : BinaryTreeRightSideView_V2.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given the root of a binary tree, imagine yourself standing on the right side of it,
//               return the values of the nodes you can see ordered from top to bottom.
//============================================================================
#include <iostream>
#include <vector>
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
private:
    vector<int> res;

public:
    vector<int> rightSideView(TreeNode *root)
    {
        orderLevel(root, 0);
        return res;
    }

    void orderLevel(TreeNode *root, int level)
    {
        if (root == nullptr)
        {
            return;
        }

        if (res.size() == level)
        {
            res.push_back(root->val);
        }

        orderLevel(root->right, level + 1);
        orderLevel(root->left, level + 1);

        // for the left side view
        // orderLevel(root->left, level + 1);
        // orderLevel(root->right, level + 1);
    }
};

int main()
{
    //        1
    //      /   \
    //     2     3
    //      \     \
    //       5     4
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node3->right = node4;
    node2->right = node5;
    Solution *solution = new Solution();
    vector<int> result = solution->rightSideView(node1);
    cout << "[" << result[0];
    for (int i = 1; i < result.size(); i++)
    {
        cout << ", " << result[i];
    }
    cout << "]";
    return 0;
}
