#include <iostream>
#include <string>
#include <vector>
#include "Bouquet.h"
#include "Flower.h"
#ifndef FLORIST_H
#define FLORIST_H

using namespace std;

class Florist {
private:
   string name;

public:
    // Конструктор за замовчуванням
    Florist() : name("Unnamed florist") {
       cout << "Florist def" <<endl;
    }

    // Перевантажений конструктор
    Florist(const string& name) : name(name) {
       cout << "Florist create: " << this->name << "." <<endl;
    }

    // Деструктор
    ~Florist() {
       cout << "Florist destroed: " << this->name << "." <<endl;
    }

    // Метод для створення букета
    Bouquet createBouquet(const string& bouquetName, const vector<Flower>& flowerList) const {
        Bouquet bouquet(bouquetName);
        for (const auto& flower : flowerList) {
            bouquet.addFlower(flower);
        }
        return bouquet;
    }

    // Метод для виведення імені флориста
    void displayName() const {
       cout << "Florist: " << name <<endl;
    }
};



#endif //FLORIST_H
