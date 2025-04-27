#include <iostream>
#include <string>
#ifndef FLOWER_H
#define FLOWER_H

using namespace std;

class Flower {

private:
    string name;
    string color;
    double price;
    int shelfLifeDays;

public:
    // Конструктор за замовчуванням
    Flower() : name("Unknown"), color("Unknown"), price(0.0), shelfLifeDays(0) {
        cout << "Flower def." << endl;
    }

    // Перевантажений конструктор
    Flower(const string& name, const string& color, double price, int shelfLifeDays)
        : name(name), color(color), price(price), shelfLifeDays(shelfLifeDays) {
        cout << "Flower create: " << this->name << "." << endl;
    }

    // Конструктор копіювання (за замовчуванням згенерований компілятором працює добре для простих типів)

    // Деструктор
    ~Flower() {
        cout << "was destroyed " << this->name << "." << endl;
    }

    // Методи доступу (геттери)
    string getName() const { return name; }
    string getColor() const { return color; }
    double getPrice() const { return price; }
    int getShelfLifeDays() const { return shelfLifeDays; }

    // Метод для виведення інформації про квітку
    void displayInfo() const {
        cout << "Name: " << name << ", Color: " << color
                  << ", Price: " << price << " grn, Expiration date: " << shelfLifeDays << " days" << endl;
    }
};

#endif