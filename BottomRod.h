#include <iostream>
#include <string>
#include "FishingRod.h"
#ifndef BOTTOMROD_H
#define BOTTOMROD_H

using namespace std;

class BottomRod : public FishingRod {
public:
    BottomRod() {
        this->type = "UL-CHUBER™ La Cazadora";
        this->price = 40000;
        this->material = "Viper";
    }

    BottomRod(double p, string m) : FishingRod("Bottom", p, m) {
        this->price = p;
        this->material = m;
    }

    // Виведення інформації про донну вудку
    void displayInfo() const override {
        cout << "Bottom: ";
        FishingRod::displayInfo();
    }
    ~BottomRod() {
        cout << "SpinningRod '" << this->type << "' was deleted." << endl;
    }
};



#endif //BOTTOMROD_H
