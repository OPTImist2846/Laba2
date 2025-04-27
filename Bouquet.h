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
    vector<Flower> flowers;

public:
    // Конструктор за замовчуванням
    Bouquet() : name("No name") {}

    // Перевантажений конструктор
    Bouquet(const string& name) : name(name) {
        cout << "Bouquet create" << this->name << "." << endl;
    }

    // Конструктор копіювання
    Bouquet(const Bouquet& other) : name(other.name) {
        std::cout << "copy constr: " << other.name << std::endl;
        for (const auto& flower : other.flowers) {
            flowers.push_back(flower);
        };
    }

    Bouquet(Bouquet&& other) noexcept : name(std::move(other.name)), flowers(std::move(other.flowers)) {
        std::cout << "Bouquet move " << name << std::endl;
        other.name = "";
    }

    Bouquet createBouquet(const std::string& name, const std::vector<Flower>& flowerList) {
        Bouquet tempBouquet(name);
        for (const auto& flower : flowerList) {
            tempBouquet.addFlower(flower);
        }
        return tempBouquet; //викликано конструктор переміщення
    }

    // Деструктор
    ~Bouquet() {
        cout << "Bouquet destoyed " << this->name << "." << endl;
    }

    // Метод для додавання квітки до букета
    void addFlower(const Flower& flower) {
        flowers.push_back(flower);
    }

    // Метод для виведення інформації про букет
    void displayBouquet() const {
        cout << "Bouquet: " << name << endl;
        if (flowers.empty()) {
            cout << "Bouquet empty." << endl;
        } else {
            cout << "Bouquet composition:" << endl;
            for (const auto& flower : flowers) {
                flower.displayInfo();
            }
        }
    }
};

#endif