#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class SuperLongInt;

struct Node {
    int element;
    Node* next;

    Node(int element) : element{ element }, next{ nullptr } {}
    Node(int element, Node* next) : element{ element }, next{ next } {}
};

class List {
private:
    size_t m_size;
    Node* m_head;
    Node* m_tail;

public:
    // Constructs an empty container
    List() : m_size{ 0 }, m_head{ nullptr } , m_tail{ nullptr }{}

    // Returns the number of elements
    size_t size() const;

    // Inserts an element to the head
    void push_head(int element);

    // Inserts an element to the head
    void push_tail(int element);
    
    // Removes the head element and returns its value
    int pop_head();


    // Converts the container to std::string
    std::string to_string() const;
    
    friend SuperLongInt;
};

#endif
