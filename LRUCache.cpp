//============================================================================
// Name        : LRUCache.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : https://leetcode.com/problems/lru-cache/
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;

    Node()
    {
        key = 0;
        val = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int k, int v)
    {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
private:
    void addNode(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    int cacheCapacity;
    unordered_map<int, Node *> mp;
    Node *head = new Node();
    Node *tail = new Node();

public:
    LRUCache(int capacity)
    {
        cacheCapacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.count(key)) // if it can find key in mp
        {
            Node *temp = mp[key];
            deleteNode(temp);
            addNode(temp);
            return temp->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            addNode(temp);
            return;
        }
        if (mp.size() == cacheCapacity)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp.insert({key, head->next});
    }
};

int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);      // cache is {1=1}
    lRUCache->put(2, 2);      // cache is {1=1, 2=2}
    cout << lRUCache->get(1); // return 1
    lRUCache->put(3, 3);      // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2); // returns -1 (not found)
    lRUCache->put(4, 4);      // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1); // return -1 (not found)
    cout << lRUCache->get(3); // return 3
    cout << lRUCache->get(4); // return 4
}