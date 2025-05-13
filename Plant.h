
#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Plant {
protected:
    string name;      // Назва
    string color;     // Колір

public:

    Plant() : name("Unknown"), color("Unknown") {
        cout << "Plant default constructor" << endl;
    }

    // Конструктор з параметрами назви та кольору
    Plant(const string& name, const string& color) : name(name), color(color) {
        cout << "Plant constructor: " << name << endl;
    }

    // Конструктор копіювання
    Plant(const Plant& other) : name(other.name), color(other.color) {
        cout << "Plant copy constructor" << endl;
    }

    // Оператор присвоєння копіюванням
    Plant& operator=(const Plant& other) {
        cout << "Plant assignment operator" << endl;
        if (this != &other) {
            name = other.name;
            color = other.color;
        }
        return *this;
    }

    // віртуальний деструктор
    virtual ~Plant() {
        cout << "Plant destructor: " << name << endl;
    }

    // oтримання назви та кольору
    string getName() const { return name; }
    string getColor() const { return color; }


    // виведення інформації про рослину
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Color: " << color;
    }
    virtual void photosynthesis() const {
        cout << "Plant is performing photosynthesis" << endl;
    }
};


#endif //PLANT_H
