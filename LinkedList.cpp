//
// Created by Benjamin Raiford on 10/24/19.
//
#include "LinkedList.h"

//Default constructor
LinkedList::LinkedList(){
    head = nullptr;
}

//Copy Constructor
LinkedList::LinkedList(const LinkedList & list){
    //Creates new node for head
    head = new Node;

    //Creates two traversing pointers, for the purpose of copying "source" nodes to "dest" nodes
    Node* current_source = list.head;
    Node* current_dest = head;

    //Copies each node, then creates a new one
    while(current_source->next != nullptr){
        current_dest->next = new Node;
        current_dest->value = current_source->value;
        current_source = current_source->next;
        current_dest = current_dest->next;
    }
}

//Copy Assignment Operator
LinkedList &LinkedList::operator=(const LinkedList &rhs) {
    LinkedList tmp(rhs);
    swap(head, tmp.head);
    return *this;
}

//Appends an item to linked list
void LinkedList::append(int item) {
    if(head == nullptr) {
        head = new Node(item);
    }
    else {
        Node *cursor = head;
        while (cursor->next != nullptr)
            cursor = cursor->next;
        cursor->next = new Node(item);
    }
}

//Prints linked list
void LinkedList::printList() {
    Node * cursor = head;
    if(!cursor)
        cout << "Empty List" << endl;
    else{
        while (cursor){
            cout << cursor->value << endl;
            cursor = cursor->next;
        }
    }
}

//Sorts linked list
void LinkedList::InsertionSort() {
    //create a "dummy" head
    Node* dummyHead = new Node();
    dummyHead->next = head;

    //Lead and trail
    Node* lead = head->next;
    Node* trail = head;

    //this node saves the location where lead should go (if lead is out of order)
    Node* endSorted;

    while(lead != nullptr){
        //traverse the list until a number is bigger than lead
        endSorted = dummyHead;
        while(endSorted->next->value < lead->value)
            endSorted = endSorted->next;
        //if trail and lead are in the right order, increment each
        if(trail->value <= lead->value){
            trail = lead;
            lead = lead->next;
        }
        //if they are not in the right order, insert lead in the spot determined by endSorted
        else{
            trail->next = lead->next;
            lead->next = endSorted->next;
            endSorted->next = lead;
            lead = trail->next;
        }
    }
    //delete "dummy" head and make the first value in the list
    head = dummyHead->next;
    dummyHead->next = nullptr;
    delete dummyHead;
}

//Destructor
LinkedList::~LinkedList() {
    delete head;
}