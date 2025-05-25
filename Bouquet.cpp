#include "Bouquet.h" // Включаємо власний заголовок

Bouquet::Bouquet() : name("No name") {
    // std::cout << "Bouquet default constructor called" << std::endl;
}

Bouquet::Bouquet(const std::string& name) : name(name) {
    // std::cout << "Bouquet constructor with name: " << name << std::endl;
}

Bouquet::Bouquet(const Bouquet& other) : name(other.name), flowers(other.flowers) {
    // std::cout << "Bouquet copy constructor called for " << name << std::endl;
}

Bouquet& Bouquet::operator=(const Bouquet& other) {
    // std::cout << "Bouquet assignment operator called for " << name << std::endl;
    if (this != &other) {
        name = other.name;
        flowers = other.flowers;
    }
    return *this;
}

Bouquet::~Bouquet() {
    // std::cout << "Bouquet destructor called for " << name << std::endl;
}

void Bouquet::addFlower(const Flower& flower) {
    flowers.push_back(flower);
    // std::cout << "Flower added to bouquet: " << name << std::endl;
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
