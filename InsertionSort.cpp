#include <cassert>
#include <iostream>
#include "LinkedList.h"

int main() {
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    LinkedList Ben;
    int randomValue;

    //generate vector and linked list of unsorted values
    for (int i = 0; i < length; i++) {
        randomValue = rand() % 100;
        Ben.append(randomValue);
    }
    std::cout << "Unsorted list:" << std::endl;
    Ben.printList();

    // linked list — InsertionSort
    std::cout << "\nSorted list:" << std::endl;
    Ben.InsertionSort();
    Ben.printList();
}