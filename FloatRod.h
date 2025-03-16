#include <iostream>
#include <string>
#include "FishingRod.h"
#ifndef FLOATROD_H
#define FLOATROD_H

using namespace std;

class FloatRod : public FishingRod{
public:
    FloatRod() :FishingRod() {
        this->type = "FloatRod";
    }

    FloatRod(string t, string m) : FishingRod(t, 10000, m) {
        this->type = t;
        this->material = m;
    }

    // Виведення інформації про поплавкову вудку
    void displayInfo() const override {
        cout << "FloatRod: ";
        FishingRod::displayInfo();
    }
};



#endif //FLOATROD_H
