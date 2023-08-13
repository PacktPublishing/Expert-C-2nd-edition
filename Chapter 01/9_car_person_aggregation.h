#ifndef CAR_H
#define CAR_H

#include <vector>
#include "person.h"
#include "engine.h"

class Car {
public: 
    Car();
    // ...
    void setDriver(Person* driver);
    void addPassenger(Person* passenger);
    // ...
private:
    Person* driver_; // aggregation
    std::vector<Person*> passengers_; // aggregation
    Engine engine_; // composition
    // ...
};

#endif // CAR_H
