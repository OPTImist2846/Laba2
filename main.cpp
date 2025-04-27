#include <iostream>
#include "Bouquet.h"
#include "Flower.h"
#include "Florist.h"

using namespace std;

int main() {
    Flower rose("Rose", "Red", 35.50, 7);
    Flower tulip("Rose", "Yellow", 20.00, 5);
    Flower chamomile("Chamomile", "White", 15.25, 6);

    Bouquet romanticBouquet("Romantic");
    romanticBouquet.addFlower(rose);
    romanticBouquet.addFlower(tulip);
    romanticBouquet.displayBouquet();

    Florist anna("Anna");
    anna.displayName();
    Bouquet springBouquet = anna.createBouquet("Spring mix", {tulip, chamomile});
    springBouquet.displayBouquet();

    return 0;
}
