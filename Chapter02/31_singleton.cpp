#include <iostream>
#include <vector>

class Product {
    // Add necessary member variables and functions for the Product class
    // For the sake of simplicity, let's assume it only has a name.
public:
    Product(const std::string& name) : name_(name) {}

    const std::string& get_name() const {
        return name_;
    }

private:
    std::string name_;
};

class Warehouse {
public:
    static Warehouse* create_instance() {
        if (instance_ == nullptr) {
            instance_ = new Warehouse();
        }
        return instance_;
    }

    static void remove_instance() {
        delete instance_;
        instance_ = nullptr;
    }

    // Function to add a product to the warehouse
    void add_product(const Product& product) {
        products_.push_back(product);
    }

private:
    Warehouse() = default;

private:
    static Warehouse* instance_;
    std::vector<Product> products_;
};

// Initialize the static member variable outside the class definition
Warehouse* Warehouse::instance_ = nullptr;

int main() {
    Warehouse* w = Warehouse::create_instance();
    Product book("Sample Book");
    w->add_product(book);
    Warehouse::remove_instance();
    return 0;
}
