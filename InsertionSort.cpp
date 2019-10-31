#include <cassert>
#include <iostream>
#include <ctime>
#include "LinkedList.h"
using namespace std;

int main() {

    int seed, length;
    cin >> seed;
    srand(seed);
    LinkedList Ben;

    for(int i = 2; i <= 10002; i = i+100){
        int randomValue;
        length = i;

        //generate linked list of unsorted values
        for (int j = 0; j < length-1; j++) {
            randomValue = rand() % 100;
            Ben.append(randomValue);
        }

        //linked list — InsertionSort and clock
        clock_t start_InsertionSort = clock();
        Ben.InsertionSort();
        clock_t end_InsertionSort = clock();
        double elapsed_InsertionSort = double(end_InsertionSort - start_InsertionSort) / CLOCKS_PER_SEC;

        //gives linked list size and time for execution
        cout << i-2 << "\t" << elapsed_InsertionSort << endl;
    }
}