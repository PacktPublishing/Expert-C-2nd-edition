#include <iostream>

// Abstract base class
class AbstractFactorial {
public:
    virtual int calculate(int n) = 0;
};

// Concrete products
class RecursiveFactorial : public AbstractFactorial {
public:
    int calculate(int n) override {
        if (n <= 1) {
            return 1;
        } else {
            return n * calculate(n - 1);
        }
    }
};

class IterativeFactorial : public AbstractFactorial {
public:
    int calculate(int n) override {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};

// Factory class
class FactorialFactory {
public:
    static AbstractFactorial* createFactorial(char type) {
        switch (type) {
        case 'R':
            return new RecursiveFactorial();
        case 'I':
            return new IterativeFactorial();
        default:
            return nullptr;
        }
    }
};

// Client code
int main() {
    AbstractFactorial* recursiveFactorial = FactorialFactory::createFactorial('R');
    int recursiveResult = recursiveFactorial->calculate(5);  // Result: 120
    std::cout << "Recursive Result: " << recursiveResult << std::endl;
    AbstractFactorial* iterativeFactorial = FactorialFactory::createFactorial('I');
    int iterativeResult = iterativeFactorial->calculate(5);  // Result: 120
    std::cout << "Iterative Result: " << iterativeResult << std::endl;

    delete recursiveFactorial;
    delete iterativeFactorial;

    return 0;
}
