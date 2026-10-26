#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortingAlgorithms.h"

void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::srand(std::time(0));
    std::vector<int> originalArray(100);

    for (int i = 0; i < 100; i++) {
        originalArray[i] = std::rand() % 500 + 1; 
    }

    std::cout << "Initial Random Array (100 elements) \n";
    printArray(originalArray);

    std::vector<int> shellArr = originalArray;
    shellSort(shellArr);
    std::cout << "Shell Sort Output \n";
    printArray(shellArr);

    std::vector<int> mergeArr = originalArray;
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    std::cout << "Merge Sort Output \n";
    printArray(mergeArr);

    std::vector<int> quickArr = originalArray;
    quickSort(quickArr, 0, quickArr.size() - 1);
    std::cout << "Quick Sort Output \n";
    printArray(quickArr);

    return 0;
}