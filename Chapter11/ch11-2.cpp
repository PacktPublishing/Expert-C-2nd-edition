#include <iostream>

class TargetInterface {
public:
    virtual void request() = 0;
};

class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee::specificRequest()" << std::endl;
    }
};

class ObjectAdapter : public TargetInterface {
public:
    ObjectAdapter(Adaptee& adaptee) : adaptee(adaptee) {}

    void request() override {
        adaptee.specificRequest();
    }

private:
    Adaptee& adaptee;
};

int main() {
    Adaptee adaptee;
    ObjectAdapter adapter(adaptee);

    adapter.request();

    return 0;
}
