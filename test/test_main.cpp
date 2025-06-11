#include <cassert>
#include "../list/list.hpp"

void test_push_front() {
    LinkedList list;
    list.push_front(10);
    assert(list.contains(10));
}

void test_push_back() {
    LinkedList list;
    list.push_back(20);
    assert(list.contains(20));
}

void test_remove() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    assert(list.remove(1));
    assert(!list.contains(1));
}

void test_contains() {
    LinkedList list;
    list.push_back(5);
    assert(list.contains(5));
    assert(!list.contains(100));
}

void test_clear() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    assert(list.empty());
}

void test_size() {
    LinkedList list;
    assert(list.size() == 0);
    list.push_back(1);
    list.push_back(2);
    assert(list.size() == 2);
}

void test_empty() {
    LinkedList list;
    assert(list.empty());
    list.push_back(3);
    assert(!list.empty());
}

void test_remove_nonexistent() {
    LinkedList list;
    list.push_back(1);
    assert(!list.remove(999));
}

void test_multiple_push() {
    LinkedList list;
    for (int i = 0; i < 10; ++i) list.push_back(i);
    assert(list.size() == 10);
}

void test_print() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print(); 
}

int main() {
    test_push_front();
    test_push_back();
    test_remove();
    test_contains();
    test_clear();
    test_size();
    test_empty();
    test_remove_nonexistent();
    test_multiple_push();
    test_print();

    std::cout << "All tests passed successfully.\n";
    return 0;
}