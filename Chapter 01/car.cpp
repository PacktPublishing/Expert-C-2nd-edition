#include "9_car_person_aggregation.h"

Car::Car() {
    driver_ = nullptr;
}

void Car::setDriver(Person* driver) {
    driver_ = driver;
}

void Car::addPassenger(Person* passenger) {
    passengers_.push_back(passenger);
}

int main(){}
