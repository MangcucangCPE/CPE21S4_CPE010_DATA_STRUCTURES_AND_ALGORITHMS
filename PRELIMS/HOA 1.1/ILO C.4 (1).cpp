#include <iostream>
using namespace std;

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();

    double area();
    double perimeter();
    void triangleType();
};

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

double Triangle::area() {
    return (5 * 4) / 2;
}

double Triangle::perimeter() {
    return 5 + 6 + 7;
}

void Triangle::triangleType() {
    if (angleA < 90 && angleB < 90 && angleC < 90)
        cout << "Triangle is Acute-angled.";
    else if (angleA > 90 || angleB > 90 || angleC > 90)
        cout << "Triangle is Obtuse-angled.";
    else
        cout << "Triangle is Others.";
}

int main() {
    Triangle set1(30, 60, 90);

    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle." << endl;
        cout << "Area: " << set1.area() << endl;
        cout << "Perimeter: " << set1.perimeter() << endl;
        set1.triangleType();
    }
    else {
        cout << "The shape is NOT a valid triangle.";
    }

    return 0;
}
