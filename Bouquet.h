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
    Bouquet();
    Bouquet(const string& name);
    Bouquet(const Bouquet& other); // Конструктор копіювання
    Bouquet& operator=(const Bouquet& other); // Оператор присвоєння копіюванням
    ~Bouquet();


    void addFlower(const Flower& flower);
    void displayBouquet() const;
    std::string getName() const;
    double getTotalPrice() const;

};

#endif // BOUQUET_H
