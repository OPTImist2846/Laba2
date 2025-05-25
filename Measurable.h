#ifndef MEASURABLE_H
#define MEASURABLE_H

class Measurable {
public:
    virtual double getMeasurement() const = 0;
    virtual std::string getUnits() const = 0;
    virtual ~Measurable() = default;
};

#endif //MEASURABLE_H