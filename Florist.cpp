#include "Florist.h" // Включаємо власний заголовок

Florist::Florist() : name("Unnamed florist") {
    // std::cout << "Florist default constructor" << std::endl;
}

Florist::Florist(const std::string& name) : name(name) {
    // std::cout << "Florist constructor with name: " << this->name << std::endl;
}

Florist::Florist(const Florist& other) : name(other.name) {
    // std::cout << "Florist copy constructor" << std::endl;
}

Florist& Florist::operator=(const Florist& other) {
    // std::cout << "Florist assignment operator" << std::endl;
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

Florist::~Florist() {
    // std::cout << "Florist destructor: " << name << std::endl;
}

Bouquet Florist::createBouquet(const std::string& bouquetName, const std::vector<Flower>& flowerList) const {
    std::cout << "Florist " << name << " is creating bouquet: " << bouquetName << std::endl;
    Bouquet bouquet(bouquetName);
    for (const auto& flower : flowerList) {
        bouquet.addFlower(flower);
    }
    return bouquet;
}

void Florist::displayName() const {
    std::cout << "Florist: " << name << std::endl;
}

std::string Florist::getName() const {
    return name;
}

