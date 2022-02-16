//============================================================================
// Name        : MergeTwoSortedLists.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : You are given the heads of two sorted linked lists list1 and list2.
//               Merge the two lists in a one sorted list.
//============================================================================
#include <iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    void appendNode(ListNode **n, int newValue)
    {
        ListNode *newNode = new ListNode();
        ListNode *last = *n;
        newNode->val = newValue;
        newNode->next = nullptr;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
    }

public:
    void ptintList(ListNode *n)
    {
        while (n->next != nullptr)
        {
            cout << n->val << " ";
            n = n->next;
        }
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // if both lists are empty then merged list is also empty
        // if one of the lists is empty then other is the merged list
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // We nead head for the merged list, 
        // It could be either first element of list1 or first element of list2.
        ListNode *mergedHead = new ListNode();
        if (list1->val <= list2->val)
        {
            mergedHead->val = list1->val;
            list1 = list1->next;
        }
        else
        {
            mergedHead->val = list2->val;
            list2 = list2->next;
        }


        // After Head, we need to create the tail.
        ListNode *mergedTail = mergedHead;
        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode *temp = new ListNode();
            if (list1->val <= list2->val)
            {
                temp->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                temp->val = list2->val;
                list2 = list2->next;
            }
            mergedTail->next = temp;
            mergedTail = mergedTail->next;
        }

        // If one of lists is completed, we can merge other list to tail.
        if (list1 != nullptr)
        {
            mergedTail->next = list1;
        }
        else if (list2 != nullptr)
        {
            mergedTail->next = list2;
        }

        return mergedHead;
    }
};

int main()
{
    Solution *solution = new Solution();

    ListNode *list11 = nullptr;
    list11 = new ListNode();
    ListNode *list12 = nullptr;
    list12 = new ListNode();
    ListNode *list13 = nullptr;
    list13 = new ListNode();

    list11->val = 1;
    list11->next = list12;
    list12->val = 2;
    list12->next = list13;
    list13->val = 4;
    list13->next = nullptr;

    ListNode *list21 = nullptr;
    list21 = new ListNode();
    ListNode *list22 = nullptr;
    list22 = new ListNode();
    ListNode *list23 = nullptr;
    list23 = new ListNode();

    list21->val = 1;
    list21->next = list22;
    list22->val = 3;
    list22->next = list23;
    list23->val = 4;
    list23->next = nullptr;

    ListNode *mergedList = solution->mergeTwoLists(list11, list21);
    solution->ptintList(mergedList);
    return 0;
}