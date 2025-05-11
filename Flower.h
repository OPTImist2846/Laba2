#include <iostream>
#include <string>
#include <vector>
#include "Plant.h"

#ifndef FLOWER_H
#define FLOWER_H

using namespace std;

class Flower : public Plant {
private:
    double price;         // Ціна квітки
    int shelfLifeDays; // Термін придатності в днях

public:
    // Конструктор за замовчуванням
    Flower() : Plant(), price(0.0), shelfLifeDays(0) {
        cout << "Flower default constructor" << endl;
    }

    // Конструктор з усіма параметрами
    Flower(const string& name, const string& color, double price, int shelfLifeDays)
        : Plant(name, color), price(price), shelfLifeDays(shelfLifeDays) {
        cout << "Flower constructor: " << name << endl;
    }

    // Конструктор з назвою, кольором та ціною
    Flower(const string& name, const string& color, double price)
        : Plant(name, color), price(price), shelfLifeDays(0) {}

    // Конструктор копіювання
    Flower(const Flower& other) : Plant(other), price(other.price), shelfLifeDays(other.shelfLifeDays) {
        cout << "Flower copy constructor" << endl;
    }

    // Оператор присвоєння копіюванням
    Flower& operator=(const Flower& other) {
        cout << "Flower assignment operator" << endl;
        if (this != &other) {
            Plant::operator=(other); // Виклик оператора присвоєння базового класу
            price = other.price;
            shelfLifeDays = other.shelfLifeDays;
        }
        return *this;
    }

    // Деструктор
    ~Flower() override {
        cout << "Flower destructor: " << name << endl;
    }

    // Гетери для отримання ціни та терміну придатності
    double getPrice() const { return price; }
    int getShelfLifeDays() const { return shelfLifeDays; }

    // Перевизначений метод для виведення інформації про квітку
    void displayInfo() const override {
        Plant::displayInfo(); // Виклик методу базового класу
        cout << ", Price: " << price << " grn, Expiration date: " << shelfLifeDays << " days" << endl;
    }
};

#endif // FLOWER_H