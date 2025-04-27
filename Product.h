#include <iostream>
#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {
        cout << "Construct Product: " << this->name << endl;
    }

    Product(const Product& other) : name(other.name), price(other.price) {
        cout << "Copy Product: " << this->name << endl;
    }

    Product(Product&& other) noexcept : name(move(other.name)), price(other.price) {
        cout << "Move Product: " << this->name << endl;
    }
    Product& operator=(const Product& other) {
        cout << "Naming Product: " << other.name << endl;
        if (this != &other) {
            name = other.name;
            price = other.price;
        }
        return *this;
    }

    Product& operator=(Product&& other) noexcept {
        cout << "Move naming Product: " << other.name << endl;
        if (this != &other) {
            name = move(other.name);
            price = other.price;
        }
        return *this;
    }

    virtual ~Product() {
        cout << "destroyed Product: " << this->name << endl;
    }


};
#endif //PRODUCT_H
