#include <iostream>
#include <vector>

// Abstract base class for shapes
class Shape {
public:
    virtual void draw() = 0;
};

// Concrete classes for rectangle and triangle
class Rectangle : public Shape {
public:
    void draw() override { std::cout << "Drawing Rectangle\n"; }
};

class Triangle : public Shape {
public:
    void draw() override { std::cout << "Drawing Triangle\n"; }
};

// Composite class for a group of shapes
class CompositeShape : public Shape {
public:
    void addShape(Shape* shape) { shapes.push_back(shape); }
    void draw() override {
        for (Shape* shape : shapes) {
            shape->draw();
        }
    }
private:
    std::vector<Shape*> shapes;
};

// Client code
int main() {
    CompositeShape compositeShape;
    compositeShape.addShape(new Rectangle());
    compositeShape.addShape(new Triangle());
    compositeShape.draw();
    return 0;
}
