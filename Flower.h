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

    Flower(const std::string& name, const std::string& color, double price)
        : name(name), color(color), price(price) {}

    friend std::ostream& operator<<(std::ostream& os, const Flower& flower) {
        os << "Name: " << flower.name << ", Colour: " << flower.color << ", Price: " << flower.price;
        return os;
    }

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