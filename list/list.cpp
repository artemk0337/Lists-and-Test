#include "list.hpp"

Node::Node(int val) : data(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

bool LinkedList::remove(int value) {
    if (!head) return false;

    if (head->data == value) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    Node* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (!current->next) return false;

    Node* tmp = current->next;
    current->next = current->next->next;
    delete tmp;
    return true;
}

bool LinkedList::contains(int value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void LinkedList::clear() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int LinkedList::size() const {
    int count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

bool LinkedList::empty() const {
    return head == nullptr;
}

void LinkedList::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}