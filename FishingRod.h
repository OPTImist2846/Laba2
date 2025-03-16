#ifndef FISHINGROD_H
#define FISHINGROD_H
#include <iostream>
#include <string>

using namespace std;

class FishingRod {
protected:
    string type; // тип вудки
    double price; // ціна
    string material; // матеріал вудки

public:
    FishingRod() {
        this->type = "FishingRod";
        this->price = 200;
        this->material = "wood";
    }

    FishingRod(string t, double p, string m) : FishingRod("FishingRod") {
        this->type = t;
        this -> price = p;
        this -> material = m;
    }

    FishingRod(string t) {
        this->type = t;
        this -> price = 100;
        this -> material = "plastic";
    }
    FishingRod(string t,double p) {
        this->type = t;
        this -> price = p;
        this -> material = "plastic";
    }
    ~FishingRod() {
        cout << "Rodtype '" << this->type << "' was deleted." << endl;
    }

    // Виведення інформації
    virtual void displayInfo() const {
        cout << "Type: " << this->type << ", Material: " << this->material << ", Price: " << this->price << " grn." << endl;
    }

    // Метод для встановлення ціни
    void setPrice(double p) {
        this->price = p;
    }

    // Метод для встановлення матеріалу
    void setMaterial(string m) {
        this->material = m;
    }

    // Метод для отримання ціни
    double getPrice() const {
        return this->price;
    }
};



#endif //FISHINGROD_H
