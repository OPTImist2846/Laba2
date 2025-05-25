
#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Plant {
protected:
    string name;      // Назва
    string color;     // Колір

public:

    Plant();
    Plant(const std::string& name, const string& color);
    Plant(const Plant& other);
    Plant& operator=(const Plant& other);
    virtual ~Plant();

    string getName() const;
    string getColor() const;



    virtual void displayInfo() const;
    virtual void photosynthesis() const;

    virtual Plant* clone() const = 0;
};


#endif //PLANT_H
