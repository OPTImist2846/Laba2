
#ifndef MEASURABLE_H
#define MEASURABLE_H
#include <string>

using namespace std;

class Measurable {
public:

    virtual double getMeasurement() const = 0;
    virtual string getUnits() const = 0;
    virtual ~Measurable() = default;
};



#endif //MEASURABLE_H
