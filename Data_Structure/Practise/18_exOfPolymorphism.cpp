#include <iostream>
#include <vector>

using namespace std;

// Base class
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}

    virtual double area()  {
        return 0;
    }

    virtual void display() const {
        cout << "This is a " << name << endl;
    }

    // Function overloading (compile-time polymorphism)
    void describe() {
        cout << "This is a shape" << endl;
    }

    void describe(string additionalInfo) {
        cout << "This is a shape. " << additionalInfo << endl;
    }
};

// Derived class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double area()  override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        Shape::display();
        cout << "Radius: " << radius << endl;
    }
};

// Another derived class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

    double area()  override {
        return width * height;
    }

    void display() const override {
        Shape::display();
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));

    // Runtime polymorphism
    for (const auto& shape : shapes) {
        shape->display();
        cout << "Area: " << shape->area() << endl << endl;
    }

    // Compile-time polymorphism (function overloading)
    Shape genericShape("Generic");
    genericShape.describe();
    genericShape.describe("It's very generic.");

    // Clean up
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}