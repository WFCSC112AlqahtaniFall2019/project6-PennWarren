#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
    friend class LinkedList;
public:
    // Default constructor
    explicit Node(int v = 0, Node* n = nullptr)
    {
        value = v;
        next = n;
    }

    //Destructor
    ~Node(){
        delete next;
    }

private:
    int value;
    Node* next;

};

#endif //NODE_H
