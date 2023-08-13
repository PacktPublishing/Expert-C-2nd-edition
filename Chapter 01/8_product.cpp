#include "product.h"

void Product::set_name(const std::string& name) {
    name_ = name;
}

std::string Product::name() const {
    return name_;
}

void Product::set_availability(bool available) {
    available_ = available;
}

bool Product::available() const {
    return available_;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << "Name: " << product.name() << "\n";
    os << "Availability: " << (product.available() ? "Yes" : "No") << "\n";
    
    return os;
}

std::istream& operator>>(std::istream& is, Product& product) {
    std::string name;
    bool available;

    std::cout << "Enter product name: ";
    std::getline(is, name);
    product.set_name(name);

    std::cout << "Is the product available? (1/0): ";
    is >> available;
    product.set_availability(available);

    return is;
}

int main(){
    Product p;
    std::cin >> p;
    std::cout << p;
    return 0;
}

