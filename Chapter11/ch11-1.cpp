#include <iostream>

class Printer {
public:
    static Printer* getInstance() {
        if (instance == nullptr) {
            instance = new Printer();
        }
        return instance;
    }

    void print(const std::string& message) {
        std::cout << message << std::endl;
    }

private:
    // Private constructor to prevent external instantiation
    Printer() {} 
    // Delete copy constructor
    Printer(const Printer&) = delete; 
    // Delete copy assignment operator
    Printer& operator=(const Printer&) = delete; 

    static Printer* instance;
};

Printer* Printer::instance = nullptr;

int main() {
    Printer* printer = Printer::getInstance();

    printer->print("Hello, world!");
    printer->print("This is a singleton printer.");

    return 0;
}
