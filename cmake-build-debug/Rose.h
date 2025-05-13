
#ifndef ROSE_H
#define ROSE_H
#include <string>
#include "Flower.h"
#include <iostream>

using namespace std;

class Rose final : public Flower, public Measurable { // Використання final
private:
    bool hasThorns; // Чи є шипи
    double stemLength;

public:
    // Конструктор за замовчуванням
    Rose() : Flower(), hasThorns(true), stemLength(0.0) {
        cout << "Rose default constructor" << endl;
    }

    // Конструктор з усіма параметрами
    Rose(const string& name, const string& color, double price, int shelfLifeDays, bool hasThorns, double stemLength)
        : Flower(name, color, price, shelfLifeDays), hasThorns(hasThorns), stemLength(stemLength) {
        cout << "Rose constructor: " << name << endl;
    }

    // Конструктор копіювання
    Rose(const Rose& other) : Flower(other), hasThorns(other.hasThorns), stemLength(other.stemLength) {
        cout << "Rose copy constructor" << endl;
    }

    // Оператор присвоєння копіюванням
    Rose& operator=(const Rose& other) {
        cout << "Rose assignment operator" << endl;
        if (this != &other) {
            Flower::operator=(other); // Виклик оператора присвоєння базового класу
            hasThorns = other.hasThorns;
            stemLength = other.stemLength;
        }
        return *this;
    }

    // Деструктор
    ~Rose() override {
        cout << "Rose destructor: " << name << endl;
    }

};



#endif //ROSE_H
