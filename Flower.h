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
    Flower();
    Flower(const std::string& name, const std::string& color, double price, int shelfLifeDays);
    Flower(const std::string& name, const std::string& color, double price);
    Flower(const Flower& other);
    Flower& operator=(const Flower& other);
    ~Flower() override;

    double getPrice() const;
    int getShelfLifeDays() const;

    void displayInfo() const override;
    void photosynthesis() const override;
};

#endif // FLOWER_H