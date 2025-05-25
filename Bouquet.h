#include <iostream>
#include <string>
#include <vector>
#include "Flower.h"
#ifndef BOUQUET_H
#define BOUQUET_H

using namespace std;

class Bouquet {
private:
    string name;
    vector<Flower> flowers; // Вектор, що зберігає квіти в букеті

public:
    Bouquet() : name("No name") {
        cout << "Bouquet default constructor called" << endl;
    }

    // Конструктор з назвою букета
    Bouquet(const string& name) : name(name) {
        cout << "Bouquet constructor with name: " << name << endl;
    }

    // Конструктор копіювання
    Bouquet(const Bouquet& other) : name(other.name), flowers(other.flowers) {
        cout << "Bouquet copy constructor called for " << name << endl;
    }

    // Оператор присвоєння копіюванням
    Bouquet& operator=(const Bouquet& other) {
        cout << "Bouquet assignment operator called for " << name << endl;
        if (this != &other) {
            name = other.name;
            flowers = other.flowers; // Deep copy
        }
        return *this;
    }

    // Деструктор
    virtual ~Bouquet() {
        cout << "Bouquet destructor called for " << name << endl;
    }

    // Метод для додавання квітки до букета
    void addFlower(const Flower& flower) {
        flowers.push_back(flower);
        cout << "Flower added to bouquet: " << name << endl;
    }

    // Метод для виведення інформації про букет
    void displayBouquet() const {
        cout << "Bouquet: " << name << endl;
        if (flowers.empty()) {
            cout << "Bouquet is empty." << endl;
        } else {
            cout << "Bouquet composition:" << endl;
            for (const auto& flower : flowers) {
                flower.displayInfo();
            }
        }
    }

    string getName() const { return name; } // Гетер для назви букета
    double getTotalPrice() const { // Метод для розрахунку загальної вартості букета
        double totalPrice = 0.0;
        for(const auto& flower : flowers) {
            totalPrice += flower.getPrice();
        }
        return totalPrice;
    }
};

#endif // BOUQUET_H
