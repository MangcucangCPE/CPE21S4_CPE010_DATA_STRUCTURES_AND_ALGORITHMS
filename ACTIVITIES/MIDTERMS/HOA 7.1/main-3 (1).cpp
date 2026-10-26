#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];

    srand(time(0));

    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }

    displayArr(unsortedArr);

    // std::cout << "\n Bubble Sort testing: \n";
    // bubbleSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    // std::cout << "\n selectionSort testing: \n";
    // selectionSort(unsortedArr, maxSize);
    // displayArr(unsortedArr);

    std::cout << "\n insertionSort testing: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}