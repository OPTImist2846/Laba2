#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовий клас для всіх вудок
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

class SpinningRod : public FishingRod {
public:
    // Конструктор
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

// Клас "Донна вудка" (успадковує FishingRod)
class BottomRod : public FishingRod {
public:
    // Конструктор
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

// Клас "Поплавочна вудка" (успадковує FishingRod)
class FloatRod : public FishingRod {
public:
    // Конструктор
    FloatRod(double p, string m) : FishingRod("FloatRod", p, m) {
        this->price = p;
        this->material = m;
    }

    // Виведення інформації про поплавкову вудку
    void displayInfo() const override {
        cout << "FloatRod: ";
        FishingRod::displayInfo();
    }
};


// Тестування програми
int main() {
    FishingRod rod;
    rod.displayInfo();

    return 0;
}
