#include <iostream>
#include <string>
using namespace std;

class Fruit {
public:
    string name;
    int price, quantity;

    Fruit(string n, int p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    ~Fruit() {}

    Fruit(const Fruit& f) {
        name = f.name;
        price = f.price;
        quantity = f.quantity;
    }

    Fruit& operator=(const Fruit& f) {
        name = f.name;
        price = f.price;
        quantity = f.quantity;
        return *this;
    }

    int calculateSum() {
        return price * quantity;
    }

    void display() {
        cout << name << " PHP " << price
             << " x" << quantity
             << " = PHP " << calculateSum() << endl;
    }
};

class Vegetable {
public:
    string name;
    int price, quantity;

    Vegetable(string n, int p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    ~Vegetable() {}

    Vegetable(const Vegetable& v) {
        name = v.name;
        price = v.price;
        quantity = v.quantity;
    }

    Vegetable& operator=(const Vegetable& v) {
        name = v.name;
        price = v.price;
        quantity = v.quantity;
        return *this;
    }

    int calculateSum() {
        return price * quantity;
    }

    void display() {
        cout << name << " PHP " << price
             << " x" << quantity
             << " = PHP " << calculateSum() << endl;
    }
};

int TotalSum(Fruit* f[], Vegetable* v[]) {
    int total = 0;

    for(int i = 0; i < 2; i++)
        total += f[i]->calculateSum();

    for(int i = 0; i < 2; i++)
        if(v[i] != NULL)
            total += v[i]->calculateSum();

    return total;
}

int main() {

    Fruit* fruits[2];
    Vegetable* vegetables[2];

    fruits[0] = new Fruit("Apple",10,7);
    fruits[1] = new Fruit("Banana",10,8);

    vegetables[0] = new Vegetable("Broccoli",60,12);
    vegetables[1] = new Vegetable("Lettuce",50,10);

    cout << "Jenna's Grocery List\n\n";

    for(int i=0;i<2;i++)
        fruits[i]->display();

    for(int i=0;i<2;i++)
        vegetables[i]->display();

    cout << "\nTotal = PHP " << TotalSum(fruits, vegetables) << endl;

    delete vegetables[1];
    vegetables[1] = NULL;

    cout << "- Lettuce:\n";
    cout << "Total = PHP " << TotalSum(fruits, vegetables) << endl;

    for(int i=0;i<2;i++)
        delete fruits[i];

    delete vegetables[0];

    return 0;
}
