#include <iostream>
#include "Bouquet.h"
#include "Flower.h"
#include "Florist.h"
#include "Price.h"
using namespace std;

int main() {
    Flower rose("Rose", "Red", 35.50, 7);
    Flower tulip("Tulip", "Yellow", 20.00, 5);
    Flower chamomile("Chamomile", "White", 15.25, 6);


    // Виведення інформації про квіти
    cout << "\nFlower Information:\n";
    rose.displayInfo();
    tulip.displayInfo();
    chamomile.displayInfo();

    // Створення вектора квітів
    vector<Flower> flowerList;
    flowerList.push_back(rose);
    flowerList.push_back(tulip);
    flowerList.push_back(chamomile);

    // Створення об'єкта Florist
    Florist florist("Alice");
    florist.displayName();

    // Створення букета флористом
    Bouquet bouquet = florist.createBouquet("Spring Bouquet", flowerList);

    // Виведення інформації про букет
    cout << "\nBouquet Information:\n";
    bouquet.displayBouquet();

    // Копіювання букета
    Bouquet copiedBouquet = bouquet;
    cout << "\nCopied Bouquet Information:\n";
    copiedBouquet.displayBouquet();std::cout << rose << std::endl;

    Bouquet romanticBouquet("Romantic");
    romanticBouquet.addFlower(rose);
    romanticBouquet.addFlower(tulip);
    romanticBouquet.displayBouquet();


    Bouquet originalBouquet("Lite");
    originalBouquet.addFlower(rose);

    return 0;
}
