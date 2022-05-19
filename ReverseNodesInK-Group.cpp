//============================================================================
// Name        : ReverseNodesInK-Group.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/reverse-nodes-in-k-group/
//============================================================================
#include <iostream>
using namespace std;

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

    // This function reverses k nodes of a list
    // head is first node of the list
    ListNode *reverseLinkedList(ListNode *head, int k)
    {
        ListNode *newHead = nullptr; // newHead is first node after reversing
        ListNode *ptr = head;

        while (k > 0)
        {
            ListNode *nextNode = ptr->next; // next node in original order

            ptr->next = newHead;
            newHead = ptr;

            ptr = nextNode;

            k--;
        }

        // Return the head of the reversed list
        return newHead;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *ptr = head;
        ListNode *kTail = nullptr;

        ListNode *newHead = nullptr;

        // while there are node in the list, continue
        while (ptr != nullptr)
        {
            int count = 0;

            // head always point to starting node on next set containig k nodes.
            // we need to start reversing from there.
            ptr = head;

            // find head of next set
            while (count < k && ptr != nullptr)
            {
                ptr = ptr->next;
                count++;
            }

            // if there are k nodes reverse them.
            if (count == k)
            {
                // reverse k nodes and get new head after reverse for current set
                ListNode *revHead = reverseLinkedList(head, k);

                // if it is for first set, it is head of final list
                if (newHead == nullptr)
                {
                    newHead = revHead;
                }

                // kTail is tail of previous set of reversed k nodes
                // So, if this is not first time,
                // we need to connect previous set to current set.
                if (kTail != nullptr)
                {
                    kTail->next = revHead;
                }

                kTail = head;
                head = ptr;
            }
        }

        // if there is an un-reverse set with nodes less than k,
        // this part shoud be atached to the tail of previous set of reversed k nodes
        // head contains ptr now. ptr is pointing to next node after current reversed set.
        // i.e. starting of the un-reverse set
        if (kTail != nullptr)
        {
            kTail->next = head;
        }

        return newHead == nullptr ? head : newHead;
    }
};

void printRevesedList(ListNode *head)
{
    ListNode *ptr = head;
    if (ptr == nullptr)
    {
        cout << "[]";
        return;
    }
    cout << "[" << ptr->val;
    ptr = ptr->next;
    while (ptr != nullptr)
    {
        cout << ", " << ptr->val;
        ptr = ptr->next;
    }
    cout << "]";
}

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    cout << "Original List: ";
    printRevesedList(node1);
    cout << "\n";
    int k = 3;
    Solution *solution = new Solution();
    ListNode *newHead = solution->reverseKGroup(node1, k);
    cout << "Reversed List with k = " << k << " : ";
    printRevesedList(newHead);
}