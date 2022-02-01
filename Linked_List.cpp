//============================================================================
// Name        : 1-Q1.cpp
// Author      : Aref Abedjooy2
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This exercise tests your knowledge of pointers in C++.
//============================================================================
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode *n)
{
    while (n != nullptr)
    {
        cout << n->val << " ";
        n = n->next;
    }
}

void push(ListNode **n, int new_val)
{
    ListNode *new_node = new ListNode();
    new_node->val = new_val;
    new_node->next = (*n);
    (*n) = new_node;
}

void append(ListNode **n, int new_val)
{
    ListNode *new_node = new ListNode();
    ListNode *last = *n;
    new_node->val = new_val;
    new_node->next = nullptr;

    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;
}

void insertAfter(ListNode *prev_node, int new_val)
{
    if (prev_node == nullptr)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    ListNode *new_node = new ListNode();
    new_node->val = new_val;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

ListNode *convert_int_to_listnode(unsigned long long int num)
{
    int remainder;
    ListNode *mainHead = new ListNode();
    remainder = num % 10;
    mainHead->val = remainder;
    num = num / 10;
    ListNode *head = mainHead;
    while (num != 0)
    {
        ListNode *nextNode = new ListNode();
        remainder = num % 10;
        nextNode->val = remainder;
        head->next = nextNode;
        head = nextNode;
        num = num / 10;
    }
    return mainHead;
}

vector<int> int_to_vector(unsigned long long int n)
{
    vector<int> vec;
    while (n != 0)
    {
        vec.push_back(n % 10);
        n /= 10;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

unsigned long long int vector_to_int(vector<int> num)
{
    unsigned long long int n = 0;
    string n_str = "";
    int N = num.size();
    for (int i = 0; i < N; i++)
    {
         n_str = n_str + to_string(num[i]);
    }
    n = stoi(n_str);
    return n;
}


vector<int> listNode_to_vector(ListNode *list){
    vector<int> vec;
    while (list !=nullptr)
    {
        vec.push_back(list->val);
        list = list->next;
    }
    return vec;
}

int main()
{
    ListNode *head = nullptr;
    ListNode *second = nullptr;
    ListNode *third = nullptr;

    head = new ListNode();
    second = new ListNode();
    third = new ListNode();

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = nullptr;

    print_list(head);
    push(&head, 11);
    cout << endl;
    print_list(head);
    append(&head, 22);
    cout << endl;
    print_list(head);
    insertAfter(second, 33);
    cout << endl;
    print_list(head);
    vector<int> numbersList =  listNode_to_vector(head);
    int number = vector_to_int(numbersList);
    cout << endl << "Number is: " << number;

    return 0;
}