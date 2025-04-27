#include "Boquet.h"

using namespace std;

class Bouquet {
private:
    string name;
    vector<Flower> flowers;

public:
    // Конструктор за замовчуванням
    Bouquet() : name("Без назви") {
        cout << "Створено об'єкт Букет за замовчуванням." << std::endl;
    }

    // Перевантажений конструктор
    Bouquet(const string& name) : name(name) {
        cout << "Створено об'єкт Букет: " << this->name << "." << std::endl;
    }

    // Конструктор копіювання (потрібно глибоке копіювання вектора квітів, якщо це необхідно)
    Bouquet(const Bouquet& other) : name(other.name), flowers(other.flowers) {
        cout << "Створено копію об'єкта Букет: " << this->name << "." << std::endl;
    }

    // Деструктор
    ~Bouquet() {
        std::cout << "Знищено об'єкт Букет: " << this->name << "." << std::endl;
    }

    // Метод для додавання квітки до букета
    void addFlower(const Flower& flower) {
        flowers.push_back(flower);
    }

    // Метод для виведення інформації про букет
    void displayBouquet() const {
        std::cout << "Букет: " << name << std::endl;
        if (flowers.empty()) {
            std::cout << "Букет порожній." << std::endl;
        } else {
            std::cout << "Склад букета:" << std::endl;
            for (const auto& flower : flowers) {
                flower.displayInfo();
            }
        }
    }
};

class Florist {
private:
    std::string name;

public:
    // Конструктор за замовчуванням
    Florist() : name("Невідомий флорист") {
        std::cout << "Створено об'єкт Флорист за замовчуванням." << std::endl;
    }

    // Перевантажений конструктор
    Florist(const std::string& name) : name(name) {
        std::cout << "Створено об'єкт Флорист: " << this->name << "." << std::endl;
    }

    // Конструктор копіювання (за замовчуванням згенерований компілятором працює добре)

    // Деструктор
    ~Florist() {
        std::cout << "Знищено об'єкт Флорист: " << this->name << "." << std::endl;
    }

    // Метод для створення букета
    Bouquet createBouquet(const std::string& bouquetName, const std::vector<Flower>& flowerList) const {
        Bouquet bouquet(bouquetName);
        for (const auto& flower : flowerList) {
            bouquet.addFlower(flower);
        }
        return bouquet;
    }

    // Метод для виведення імені флориста
    void displayName() const {
        std::cout << "Флорист: " << name << std::endl;
    }
};

int main() {
    Flower rose("Троянда", "Червона", 35.50, 7);
    Flower tulip("Тюльпан", "Жовтий", 20.00, 5);
    Flower chamomile("Ромашка", "Біла", 15.25, 6);

    Bouquet romanticBouquet("Романтичний");
    romanticBouquet.addFlower(rose);
    romanticBouquet.addFlower(tulip);
    romanticBouquet.displayBouquet();

    Florist anna("Анна");
    anna.displayName();
    Bouquet springBouquet = anna.createBouquet("Весняний мікс", {tulip, chamomile});
    springBouquet.displayBouquet();

    return 0;
}
