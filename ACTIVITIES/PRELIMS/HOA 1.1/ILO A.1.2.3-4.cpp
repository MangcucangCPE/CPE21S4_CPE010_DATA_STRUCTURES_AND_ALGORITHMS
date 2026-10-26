#include <iostream>
using namespace std;

void sum(int a, int b);
int greaterNum(int A, int B);
bool logicalOperation(bool a, bool b);

int main() {
    int choice;

    cout << "MENU" << endl;
    cout << "1. Sum of Two Numbers" << endl;
    cout << "2. Greater Number" << endl;
    cout << "3. Logical Operations" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int num1, num2;
        cout << "\nEnter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        sum(num1, num2);
        break;
    }

    case 2: {
        int A, B;
        cout << "\nEnter value of A: ";
        cin >> A;
        cout << "Enter value of B: ";
        cin >> B;
        cout << "Greater value: " << greaterNum(A, B) << endl;
        break;
    }

    case 3: {
        bool x, y;
        cout << "\nEnter first value (1 or 0): ";
        cin >> x;
        cout << "Enter second value (1 or 0): ";
        cin >> y;
        logicalOperation(x, y);
        break;
    }

    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}


void sum(int a, int b) {
    cout << "Sum: " << a + b << endl;
}

int greaterNum(int A, int B) {
    if (A > B)
        return A;
    else
        return B;
}

bool logicalOperation(bool a, bool b) {
    cout << "AND: " << (a && b) << endl;
    cout << "OR: " << (a || b) << endl;
    cout << "NOT A: " << (!a) << endl;
    cout << "NOT B: " << (!b) << endl;

    return true;
}
