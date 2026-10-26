#include <iostream>
using namespace std;

// Regular recursive power
int rpower(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * rpower(x, n - 1);
}

// Binary recursive power
int brpower(int x, int n) {
    if (n == 0)
        return 1;

    if (n % 2 != 0) {
        int y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    if (n % 2 == 0) {
        int y = brpower(x, n / 2);
        return y * y;
    }

    return 0;
}

int main() {
    int x = 2;
    int n = 10;

    cout << "rpower(" << x << ", " << n << ") = "
         << rpower(x, n) << endl;

    cout << "brpower(" << x << ", " << n << ") = "
         << brpower(x, n) << endl;

    return 0;
}
