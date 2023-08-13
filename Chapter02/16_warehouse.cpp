#include <iostream>

class Product {
    // Code omitted for brevity
};

class Warehouse {
public:
    Warehouse()
        : size_{ 0 }, capacity_{ 1000 }, products_{ nullptr }
    {
        products_ = new Product[capacity_];
    }

    // Copy constructor
    Warehouse(const Warehouse& other)
        : size_{ other.size_ }, capacity_{ other.capacity_ }, products_{ nullptr }
    {
        products_ = new Product[capacity_];
        for (int i = 0; i < size_; ++i) {
            products_[i] = other.products_[i];
        }
    }

    // Copy assignment operator
    Warehouse& operator=(const Warehouse& other) {
        if (this != &other) {
            delete[] products_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            products_ = new Product[capacity_];
            for (int i = 0; i < size_; ++i) {
                products_[i] = other.products_[i];
            }
        }
        return *this;
    }

    ~Warehouse() {
        delete[] products_;
    }

public:
    void add_product(const Product& p) {
        if (size_ == capacity_) {
            resize();
        }
        products_[size_++] = p;
    }

    // other functions omitted for brevity

private:
    int size_;
    int capacity_;
    Product* products_;

    void resize() {
        capacity_ *= 2;
        Product* newProducts = new Product[capacity_];
        for (int i = 0; i < size_; ++i) {
            newProducts[i] = products_[i];
        }
        delete[] products_;
        products_ = newProducts;
    }
};

int main() {
    Warehouse w1;
    Product book;
    Product apple;
    // ...assign values to products (omitted for brevity)
    w1.add_product(book);
    Warehouse w2 = w1; // copy
    w2.add_product(apple);
    // Now w2 is a copy of w1 with an additional product
}
