
#include "Plant.h"

Plant::Plant() : name("Unknown"), color("Unknown") {}
Plant::Plant(const std::string& name, const std::string& color) : name(name), color(color) {}
Plant::Plant(const Plant& other) : name(other.name), color(other.color) {}
Plant& Plant::operator=(const Plant& other) {
    if (this != &other) {
        name = other.name;
        color = other.color;
    }
    return *this;
}
Plant::~Plant() {}

std::string Plant::getName() const { return name; }
std::string Plant::getColor() const { return color; }
void Plant::displayInfo() const { std::cout << "Name: " << name << ", Color: " << color; }
void Plant::photosynthesis() const { std::cout << "Plant is performing photosynthesis" << std::endl; }