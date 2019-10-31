#include <cassert>
#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main() {

    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);
    LinkedList Ben;
    int randomValue;

    //generate vector and linked list of unsorted values
    for (int & i : v) {
        randomValue = rand() % 100;
        i = randomValue;
        Ben.append(randomValue);
    }

    // vector — binary insertion sort
    insertionSort(v, v.size());

    // linked list — InsertionSort
    Ben.InsertionSort();
    Ben.printList();

}