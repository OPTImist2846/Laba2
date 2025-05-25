#include "Bouquet.h" // Включаємо власний заголовок

Bouquet::Bouquet() : name("No name") {}
Bouquet::Bouquet(const std::string& name) : name(name) {}
Bouquet::Bouquet(const Bouquet& other) : name(other.name), flowers(other.flowers) {}
Bouquet& Bouquet::operator=(const Bouquet& other) {

    if (this != &other) {
        name = other.name;
        flowers = other.flowers;
    }
    return *this;
}

Bouquet::~Bouquet() {}

void Bouquet::addFlower(const Flower& flower) {
    flowers.push_back(flower);
}

void Bouquet::displayBouquet() const {
    std::cout << "Bouquet: " << name << std::endl;
    if (flowers.empty()) {
        std::cout << "  Bouquet is empty." << std::endl;
    } else {
        std::cout << "  Bouquet composition:" << std::endl;
        for (const auto& flower : flowers) {
            flower.displayInfo();
            std::cout << std::endl;
        }
    }
}

std::string Bouquet::getName() const { return name; }

double Bouquet::getTotalPrice() const {
    double totalPrice = 0.0;
    for(const auto& flower : flowers) {
        totalPrice += flower.getPrice();
    }
    return totalPrice;
}
