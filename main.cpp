#include <iostream>
#include "FishingRod.h"
#include "BottomRod.h"
#include "SpinningRod.h"
#include "FloatRod.h"

using namespace std;


int main() {
    cout << "FISTING ROD!!!" << endl;
    FishingRod rod1;
    FishingRod rod2("Ahuenna");
    FishingRod rod3("Zalupna",1000000);
    FishingRod rod4("Pesdataja",23,"Gowno");

    rod1.displayInfo();
    rod2.displayInfo();
    rod3.displayInfo();
    rod4.displayInfo();

    cout << "BOTTOM ROD EBAW!!!" << endl;
    BottomRod brod1;
    BottomRod brod2(98, "wool");

    brod1.displayInfo();
    brod2.displayInfo();

    cout << "FLOAT ROD EBAW JA W ROT!!!" << endl;
    FloatRod frod1;
    FloatRod frod2("Float","Sponge");

    frod1.displayInfo();
    frod2.displayInfo();

    cout << "SPINNING ROD <HOOK IN ASS>!!!" << endl;
    SpinningRod srod1(18500,"MDMA");
    return 0;
}
