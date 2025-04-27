#include <iostream>
#include <string>
#include "Product.h"
#ifndef FLORALPRODUCT_H
#define FLORALPRODUCT_H

class FloralProduct : public Product {
protected:
    int shelfLifeDays;

public:
    FloralProduct(const string& name, double price, int shelfLifeDays)
        : Product(name, price), shelfLifeDays(shelfLifeDays) {
        cout << "Конструктор FloralProduct: " << this->name << endl;
    }

    FloralProduct(const FloralProduct& other) : Product(other), shelfLifeDays(other.shelfLifeDays) {
        cout << "copy FloralProduct: " << this->name << endl;
    }

    FloralProduct(FloralProduct&& other) noexcept : Product(move(other)), shelfLifeDays(other.shelfLifeDays) {
        cout << "move FloralProduct: " << this->name << endl;
    }

    FloralProduct& operator=(const FloralProduct& other) {
        cout << "Оператор присвоєння FloralProduct: " << other.name << endl;
        if (this != &other) {
            Product::operator=(other);
            shelfLifeDays = other.shelfLifeDays;
        }
        return *this;
    }

    FloralProduct& operator=(FloralProduct&& other) noexcept {
        cout << "Naming FloralProduct: " << other.name << endl;
        if (this != &other) {
            Product::operator=(move(other));
            shelfLifeDays = other.shelfLifeDays;
        }
        return *this;
    }

    ~FloralProduct() override {
        cout << "destroyed FloralProduct: " << this->name << endl;
    }

    int getShelfLifeDays() const { return shelfLifeDays; }

    void displayInfo() const override {
        Product::displayInfo();
        cout << "Expiration date: " << shelfLifeDays << " days." << endl;
    }
};

#endif //FLORALPRODUCT_H
