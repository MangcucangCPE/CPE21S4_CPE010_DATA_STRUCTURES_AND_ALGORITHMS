#include <iostream>
#include <cmath>
using namespace std;

void swapNumbers(int &, int &);
double kelvinToFahrenheit(double);
double distance(double, double, double, double);

int main()
{
    int choice;

    cout << "MENU" << endl;
    cout << "1. Swap Two Numbers" << endl;
    cout << "2. Kelvin to Fahrenheit" << endl;
    cout << "3. Distance Between Two Points" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int num1, num2;

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Before Swapping:" << endl;
        cout << "First Number = " << num1 << endl;
        cout << "Second Number = " << num2 << endl;

        swapNumbers(num1, num2);

        cout << "After Swapping:" << endl;
        cout << "First Number = " << num1 << endl;
        cout << "Second Number = " << num2 << endl;
    }
    else if (choice == 2)
    {
        double kelvin, fahrenheit;

        cout << "Enter temperature in Kelvin: ";
        cin >> kelvin;

        fahrenheit = kelvinToFahrenheit(kelvin);

        cout << "Temperature in Fahrenheit = " << fahrenheit << endl;
    }
    else if (choice == 3)
    {
        double x1, y1, x2, y2, result;

        cout << "Enter x1: ";
        cin >> x1;

        cout << "Enter y1: ";
        cin >> y1;

        cout << "Enter x2: ";
        cin >> x2;

        cout << "Enter y2: ";
        cin >> y2;

        result = distance(x1, y1, x2, y2);

        cout << "Distance = " << result << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}


void swapNumbers(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

double kelvinToFahrenheit(double k)
{
    return (k - 273.15) * 9 / 5 + 32;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
