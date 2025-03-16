#include <iostream>
#include <string>
#include "FishingRod.h"
#ifndef SPINNINGROD_H
#define SPINNINGROD_H

using namespace std;


class SpinningRod : public FishingRod {
public:
    SpinningRod(){
        this->price = 4389;
        this->material = "Viper";
        this->type = "Spinning";
    }

    SpinningRod(double p, string m) : FishingRod("Spining", p, m) {
        this->price = p;
        this->material = m;
    }

    // Виведення інформації про спінінг
    void displayInfo() const override {
        cout << "Spinning: ";
        FishingRod::displayInfo();
    }
    ~SpinningRod() {
        cout << "SpinningRod '" << this->type << "' was deleted." << endl;
    }
};



#endif //SPINNINGROD_H
