#include <iostream>
using namespace std;

bool Unique(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;

    if (Unique(A, n))
        cout << "All elements are unique." << endl;
    else
        cout << "There are duplicate elements." << endl;

    return 0;
}

