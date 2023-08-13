#include "person.h"

Person::Person(const std::string& name, int age) : name_(name), age_(age) {}

const std::string& Person::getName() const {
    return name_;
}

int Person::getAge() const {
    return age_;
}

