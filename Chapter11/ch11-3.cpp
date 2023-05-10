#include <iostream>

// Target interface
class TargetInterface {
public:
    virtual int add(int a, int b) = 0;
};

// Adaptee class with incompatible interface
class Adaptee {
public:
    int sum(int a, int b) {
        return a + b;
    }
};

// Class adapter
class ClassAdapter : public TargetInterface, private Adaptee {
public:
    int add(int a, int b) override {
        return sum(a, b);
    }
};

int main() {
    ClassAdapter adapter;

    int result = adapter.add(3, 4);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
