#include "Florist.h" // Включаємо власний заголовок

Florist::Florist() : name("Unnamed florist") {}
Florist::Florist(const std::string& name) : name(name) {}
Florist::Florist(const Florist& other) : name(other.name) {}
Florist& Florist::operator=(const Florist& other) {

    if (this != &other) {
        name = other.name;
    }
    return *this;
}

Florist::~Florist() {}

Bouquet Florist::createBouquet(const std::string& bouquetName, const std::vector<Flower*>& flowerPointers) const {
    std::cout << "Florist " << name << " is creating bouquet: " << bouquetName << std::endl;
    Bouquet bouquet(bouquetName);
    for (const auto& flowerPtr : flowerPointers) { // Ітеруємо по покажчиках
        if (flowerPtr) { // Перевіряємо, чи покажчик не є nullptr
            bouquet.addFlower(*flowerPtr); // Викликаємо addFlower з розіменованим покажчиком
        }
    }
    return bouquet;
}

void Florist::displayName() const {
    std::cout << "Florist: " << name << std::endl;
}

std::string Florist::getName() const {
    return name;
}
