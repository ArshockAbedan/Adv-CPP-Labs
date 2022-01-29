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

// void push(struct Node ** head_ref, int new_data) {
//     struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));
//     new_node->data = new_data;
//     new_node->next = ( * head_ref);
//     ( * head_ref) = new_node;
// }

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

    return 0;
}