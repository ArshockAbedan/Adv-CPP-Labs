//============================================================================
// Name        : ValidateBinarySearchTree.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : Given the root of a binary tree,
//               determine if it is a valid binary search tree (BST).
//============================================================================
#include <iostream>
#include <cassert>
#include <limits>
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
    bool isValidBST(TreeNode *root)
    {
        return isValidBSTRng(root,
                             numeric_limits<long long int>::min(),
                             numeric_limits<long long int>::max());
    }

    // Check left subtree and right subtree recursively.
    bool isValidBSTRng(TreeNode *root, long long int min, long long int max)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->val >= min || root->val <= max)
        {
            return false;
        }

        return isValidBSTRng(root->left, min, root->val) &&
               isValidBSTRng(root->right, root->val, max);
    }
};

int main()
{
    Solution *solution = new Solution();
    //     2
    //    / \
    //   1   3
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);

    node2->left = node1;
    node2->right = node3;
    cout << solution->isValidBST(node2);
    assert(solution->isValidBST(node2) == false && "Tree is not A valid BST");

    return 0;
}