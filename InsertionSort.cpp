#include <cassert>
#include <iostream>
#include <vector>
#include <ctime>
#include "BinaryInsertionSort.h"
using namespace std;

int main() {

    int seed, length;
    cin >> seed;
    srand(seed);


    for(int i = 0; i <= 5001; i += 100){
        length = i;
        vector<int> v(length);

        // generate vector of random integers
        for (int & i : v) {
            i = rand() % 100;
        }

         // vector — binary insertion sort and clock
        clock_t start_BinaryInsertionSort = clock();
        insertionSort(v, v.size());
        clock_t end_BinaryInsertionSort = clock();
        double elapsed_BinaryInsertionSort = double(end_BinaryInsertionSort - start_BinaryInsertionSort) / CLOCKS_PER_SEC;

        //gives vector size and time for execution
        cout << i << "\t" << elapsed_BinaryInsertionSort << endl;
    }
}

