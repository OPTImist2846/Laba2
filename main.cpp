#include <iostream>
#include "Bouquet.h"
#include "Flower.h"
#include "Florist.h"

using namespace std;

int main() {
    Flower rose("Rose", "Red", 35.50, 7);
    Flower tulip("Tulip", "Yellow", 20.00, 5);
    Flower chamomile("Chamomile", "White", 15.25, 6);

    Bouquet romanticBouquet("Romantic");
    romanticBouquet.addFlower(rose);
    romanticBouquet.addFlower(tulip);
    romanticBouquet.displayBouquet();

    Florist anna("Anna");
    anna.displayName();
    Bouquet springBouquet = anna.createBouquet("Spring mix", {tulip, chamomile});
    springBouquet.displayBouquet();

    Bouquet originalBouquet("Lite");
    originalBouquet.addFlower(rose);

    Bouquet copiedBouquet = originalBouquet; // Виклик конструктора копіювання
    copiedBouquet.displayBouquet();

    Bouquet movedBouquet = anna.createBouquet("Yellow flowers", {tulip}); // Виклик конструктора переміщення
    movedBouquet.displayBouquet();

    return 0;
}
