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

   Florist();
   Florist(const string& name);
   Florist(const Florist& other);
   Florist& operator=(const Florist& other);
   ~Florist();

   Bouquet createBouquet(const string& bouquetName, const vector<Flower*>& flowerPointers) const; // Змінено на вектор покажчиків
   void displayName() const;
   string getName() const;
};

#endif // FLORIST_H
