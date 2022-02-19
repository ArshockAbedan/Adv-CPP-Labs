//============================================================================
// Name        : CopyListwithRandomPointer.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : A linked list of length n is given such that each node contains
//               an additional random pointer, which could point to any node in the list, or null.
//               Construct a deep copy of the list.
//============================================================================
#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }

    bool operator==(Node *&operand)
    {
        return (this->val == operand->val) && (this->next == operand->next) && (this->random == operand->random);
    }
};

class Solution
{
private:
public:
    Node *copyRandomList(Node *head)
    {
        if(head == nullptr){
            return nullptr;
        }

        Node* curr = head;
        Node* temp;

        //insert additional nodes after each node in original list
        while (curr)
        {
            temp = curr->next;
            // insert new node
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        curr = head;

        // adjust random pointers of newly added nodes
        while (curr)
        {
            if(curr->next){
                curr->next->random = curr->random? curr->random->next : curr->random;
            }
            // Moving to nxt newly added node 
            // by skipping one original node
            curr = curr->next? curr->next->next : curr->next;
        }


        Node* original = head;
        Node* copy = head->next;

        // save start of copy list
        temp = copy;

        // seperate original list and copy list
        while(original && copy){
            original->next = original->next? original->next->next : original->next;
            copy->next = copy->next? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }
        return temp;
    }

    string getIndexOfNode(Node *node, Node *head)
    {
        int index = -1;
        string return_str = "null";
        while (head)
        {
            index++;
            if (head == node)
            {
                return to_string(index);
            }
            head = head->next;
        }
        return "null";
    }

    void print_list(Node *head)
    {
        Node *temp_header = head;
        string index_str;
        if (head == nullptr)
        {
            cout << "[]";
        }
        else
        {
            cout << "[";
            while (head)
            {
                index_str = getIndexOfNode(head->random, temp_header);
                cout << "[" << head->val << "," << index_str << "]";
                if (head->next != nullptr)
                {
                    cout << ",";
                }
                head = head->next;
            }
            cout << "]";
        }
    }
};

int main()
{
    Solution *solution = new Solution();
    Node *node1 = new Node(7);
    Node *node2 = new Node(13);
    Node *node3 = new Node(11);
    Node *node4 = new Node(10);
    Node *node5 = new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    cout << "head = " ;
    solution->print_list(node1);
    cout << endl << "Deep Copy: ";
    solution->print_list(solution->copyRandomList(node1));
}