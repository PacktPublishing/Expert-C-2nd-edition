#include <iostream>
#include <vector>

class MouseEvent {
public:
    MouseEvent(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

private:
    int x;
    int y;
};

class MouseMoveObserver {
public:
    virtual void onMouseMove(const MouseEvent& event) = 0;
};

class MouseMoveSubject {
public:
    void attach(MouseMoveObserver* observer) {
        observers.push_back(observer);
    }

    void detach(MouseMoveObserver* observer) {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notify(const MouseEvent& event) {
        for (auto observer : observers) {
            observer->onMouseMove(event);
        }
    }

private:
    std::vector<MouseMoveObserver*> observers;
};

class MouseMoveLogger : public MouseMoveObserver {
public:
    void onMouseMove(const MouseEvent& event) override {
        std::cout << "Mouse moved to (" << event.getX() << ", " << event.getY() << ")" << std::endl;
    }
};

class MouseMovePrinter : public MouseMoveObserver {
public:
    void onMouseMove(const MouseEvent& event) override {
        std::cout << "Mouse move event received" << std::endl;
    }
};

int main() {
    MouseMoveSubject subject;
    MouseMoveLogger logger;
    MouseMovePrinter printer;

    subject.attach(&logger);
    subject.attach(&printer);

    MouseEvent event(42, 1337);

    subject.notify(event);

    subject.detach(&printer);

    event = MouseEvent(1337, 42);

    subject.notify(event);

    return 0;
}
