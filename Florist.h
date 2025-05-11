#include <iostream>
#include <string>
#include <vector>
#include "Bouquet.h"
#include "Flower.h"
#ifndef FLORIST_H
#define FLORIST_H

using namespace std;

class Florist {
private:
   string name;

public:
   // Конструктор за замовчуванням
   Florist() : name("Unnamed florist") {
      cout << "Florist default constructor" << endl;
   }

   // Конструктор з ім'ям флориста
   Florist(const string& name) : name(name) {
      cout << "Florist constructor with name: " << this->name << endl;
   }

   // Конструктор копiювання
   Florist(const Florist& other) : name(other.name)
   {
      cout << "Florist copy constructor" << endl;
   }

   // Оператор присвоєння копіюванням
   Florist& operator=(const Florist& other) {
      cout << "Florist assignment operator" << endl;
      if (this != &other) {
         name = other.name;
      }
      return *this;
   }
   // Деструктор
   ~Florist() {
      cout << "Florist destructor: " << name << endl;
   }

   // Метод для створення букета
   Bouquet createBouquet(const string& bouquetName, const vector<Flower>& flowerList) const {
      cout << "Florist " << name << " is creating bouquet: " << bouquetName << endl;
      Bouquet bouquet(bouquetName); // Create the bouquet with the given name
      for (const auto& flower : flowerList) {
         bouquet.addFlower(flower); // Add flowers to the bouquet
      }
      return bouquet;
   }

   // Метод для виведення імені флориста
   void displayName() const {
      cout << "Florist: " << name << endl;
   }

   // Гетер для імені флориста
   string getName() const {
      return name;
   }
};

#endif // FLORIST_H
