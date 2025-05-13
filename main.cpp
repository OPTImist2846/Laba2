#include <iostream>
#include "Bouquet.h"
#include "Flower.h"
#include "Florist.h"
#include "Price.h"
#include "Rose.h"
#include "Plant.h"
using namespace std;

int main() {
    Flower rose("Rose", "Red", 35.50, 7);
    Flower tulip("Tulip", "Yellow", 20.00, 5);
    Flower chamomile("Chamomile", "White", 15.25, 6);
    Rose rose1("Red Rose", "Red", 35.0, 12, true, 20.0);

    // Виведення інформації про квіти
    cout << "\nFlower Information:\n";
    rose.displayInfo();
    tulip.displayInfo();
    chamomile.displayInfo();
    rose1.displayInfo();

    // Створення вектора квітів
    vector<Flower> flowerList;
    flowerList.push_back(rose);
    flowerList.push_back(tulip);
    flowerList.push_back(chamomile);

    cout << "\nStatic Method Binding:\n";
    Plant plant1 = rose; // Зрізання об'єкта
    plant1.displayInfo();

    cout << "\nDynamic Polymorphism with Base Class Pointer:\n";
    Plant* plantPtr = &rose;
    plantPtr->displayInfo(); // Викликається Flower::displayInfo()
    plantPtr = &rose1;
    plantPtr->displayInfo();

    cout << "\nDynamic Polymorphism with Base Class Reference:\n";
    Plant& plantRef = rose;
    plantRef.displayInfo(); // Викликається Flower::displayInfo()
    Plant& plantRef2 = rose1;
    plantRef2.displayInfo();

    // Демонстрація виклику віртуальної функції
    cout << "\nVirtual Function Call:\n";
    plantPtr->photosynthesis(); // Викликається Flower::photosynthesis() або Rose::photosynthesis()

    // Демонстрація використання інтерфейсу
    cout << "\nInterface Demonstration:\n";
    Measurable* measurablePtr = &rose1;
    cout << "Rose stem length: " << measurablePtr->getMeasurement() << measurablePtr->getUnits() << endl;

    // Демонстрація виклику віртуального деструктора
    cout << "\nVirtual Destructor Call:\n";
    delete plantPtr; // Викликається спочатку деструктор Rose, потім Flower, потім Plant

    // Створення об'єкта Florist
    Florist florist("Alice");
    florist.displayName();

    // Створення букета флористом
    Bouquet bouquet = florist.createBouquet("Spring Bouquet", flowerList);

    // Виведення інформації про букет
    cout << "\nBouquet Information:\n";
    bouquet.displayBouquet();


    Bouquet romanticBouquet("Romantic");
    romanticBouquet.addFlower(rose);
    romanticBouquet.addFlower(tulip);
    romanticBouquet.displayBouquet();


    Bouquet originalBouquet("Lite");
    originalBouquet.addFlower(rose);

    return 0;
}
