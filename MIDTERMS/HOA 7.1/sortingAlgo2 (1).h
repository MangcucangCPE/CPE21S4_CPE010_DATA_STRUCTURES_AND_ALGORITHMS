#ifndef SORTINGALGO2_H
#define SORTINGALGO2_H

template <typename T>
void insertionSort(T arr[], int maxSize) {
    for (int k = 1; k < maxSize; k++) {
        T temp = arr[k];
        int j = k - 1;

        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

#endif