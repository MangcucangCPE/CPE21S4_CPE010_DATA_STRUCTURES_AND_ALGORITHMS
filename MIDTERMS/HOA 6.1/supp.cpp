#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void searchArray() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int target = 18;
    int count = 0;

    for (int i = 0; i < 10; i++) {
        count++;
        if (arr[i] == target) {
            cout << "Array comparisons: " << count << "\n";
            break;
        }
    }
}

void searchList() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    Node* head = new Node{arr[0], nullptr};
    Node* curr = head;
    for (int i = 1; i < 10; i++) {
        curr->next = new Node{arr[i], nullptr};
        curr = curr->next;
    }

    int target = 18;
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        if (temp->data == target) {
            cout << "Linked List comparisons: " << count << "\n";
            break;
        }
        temp = temp->next;
    }
}

void countElements() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int target = 18;
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    cout << "Count: " << count << "\n";
}

void binaryIterative() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int target = 8;
    int low = 0;
    int high = 9;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            cout << "Iterative Index: " << mid << "\n";
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

int binaryRecursive(int arr[], int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binaryRecursive(arr, low, mid - 1, target);
    return binaryRecursive(arr, mid + 1, high, target);
}

void runBinaryRecursive() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int target = 8;

    int index = binaryRecursive(arr, 0, 9, target);
    cout << "Recursive Index: " << index << "\n";
}

int main() {
    searchArray();
    searchList();
    countElements();
    binaryIterative();
    runBinaryRecursive();

    return 0;
}