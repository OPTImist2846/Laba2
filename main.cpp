#include <iostream>
#include "FishingRod.h"
#include "BottomRod.h"
#include "SpinningRod.h"
#include "FloatRod.h"

using namespace std;


int main() {
    cout << "FISTING ROD!!!" << endl;
    FishingRod rod1;
    FishingRod rod2("Norm");
    FishingRod rod3("Top",32700);
    FishingRod rod4("Tak sobi",12500,"Wood");
    FishingRod rod5;

    rod1.displayInfo();
    rod2.displayInfo();
    rod3.displayInfo();
    rod4.displayInfo();
    cin>>rod5;
    cout<<rod5<< endl;
    cout << "BOTTOM ROD NALETAI NAROD!!!" << endl;
    BottomRod brod1;
    BottomRod brod2(20400, "Titan");

    brod1.displayInfo();
    brod2.displayInfo();

    cout << "FLOAT ROD, ROZBERAI NAROD!!!" << endl;
    FloatRod frod1;
    FloatRod frod2("Garry Scott Brutus","Cork");

    frod1.displayInfo();
    frod2.displayInfo();

    cout << "SPINNING ROD KUPI PLIS!!" << endl;
    SpinningRod srod1(18500,"Platina");

    return 0;
}
