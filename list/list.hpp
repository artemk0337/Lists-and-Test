#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val);
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void push_front(int value);
    void push_back(int value);
    bool remove(int value);
    bool contains(int value) const;
    void clear();
    int size() const;
    bool empty() const;
    void print() const;

private:
    Node* head;
};