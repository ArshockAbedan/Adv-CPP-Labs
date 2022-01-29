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
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print_list(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
}




void push(Node **n, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*n);
    (*n) = new_node;
}


void append(Node **n, int new_data){
    Node *new_node = new Node();
    Node *last = *n;
    new_node->data = new_data;
    new_node->next = nullptr;

    while(last->next != nullptr){
        last = last->next;
    }
    last->next = new_node;
}


void insertAfter(Node* prev_node, int new_data){
    if (prev_node == nullptr) {
        cout << "the given previous node cannot be NULL";
        return;
    }

     Node *new_node = new Node();
     new_node->data = new_data;
     new_node->next = prev_node->next;
     prev_node->next = new_node;
}



int main()
{
    Node *head = nullptr;
    Node *second = nullptr;
    Node *third = nullptr;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
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

    return 0;
}