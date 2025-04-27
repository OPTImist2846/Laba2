#include <iostream>

class Price {
private:
    double amount;

public:
    Price(double a = 0.0) : amount(a) {}

    // Перевантаження оператора додавання (obj1 + obj2)
    Price operator+(const Price& other) const {
        return Price(amount + other.amount);
    }

    double getAmount() const {
        return amount;
    }
};
