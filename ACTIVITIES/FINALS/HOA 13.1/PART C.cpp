#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>

// Standard Merge Step
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < k; ++p) {
        arr[left + p] = temp[p];
    }
}


void mergeSortSequential(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    
    mergeSortSequential(arr, left, mid);
    mergeSortSequential(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


void mergeSortParallel(std::vector<int>& arr, int left, int right, int depth) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    if (depth < 3) { 
        std::thread t1(mergeSortParallel, std::ref(arr), left, mid, depth + 1);
        std::thread t2(mergeSortParallel, std::ref(arr), mid + 1, right, depth + 1);
        t1.join();
        t2.join();
    } else {
        mergeSortSequential(arr, left, mid);
        mergeSortSequential(arr, mid + 1, right);
    }

    merge(arr, left, mid, right);
}


int main() {
    int N = 1000000;
    std::vector<int> arr1(N), arr2(N);

    std::mt19937 rng(42);
    for (int i = 0; i < N; ++i) {
        int val = rng() % 1000000;
        arr1[i] = val;
        arr2[i] = val;
    }

    
    auto startParallel = std::chrono::high_resolution_clock::now();
    mergeSortParallel(arr1, 0, N - 1, 0);
    auto endParallel = std::chrono::high_resolution_clock::now();

    auto startSeq = std::chrono::high_resolution_clock::now();
    mergeSortSequential(arr2, 0, N - 1);
    auto endSeq = std::chrono::high_resolution_clock::now();

    auto parallelTime = std::chrono::duration_cast<std::chrono::milliseconds>(endParallel - startParallel).count();
    auto seqTime = std::chrono::duration_cast<std::chrono::milliseconds>(endSeq - startSeq).count();

    std::cout << "Sequential Merge Sort Time: " << seqTime << " ms\n";
    std::cout << "Parallel Merge Sort Time:   " << parallelTime << " ms\n";

    return 0;
}