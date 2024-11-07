#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function for runtime polymorphism
    virtual double area() {
        return 0;
    }

    // Virtual function for displaying information
    virtual void display() const {
        cout << "This is a shape." << endl;
    }

    // Function overloading (compile-time polymorphism)
    void describe() {
        cout << "This is a basic shape." << endl;
    }

    void describe(string additionalInfo) {
        cout << "This is a shape. " << additionalInfo << endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Overriding the area() function
    double area() override {
        return 3.14159 * radius * radius;
    }

    // Overriding the display() function
    void display() const override {
        cout << "This is a circle with radius " << radius << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Overriding the area() function
    double area() override {
        return width * height;
    }

    // Overriding the display() function
    void display() const override {
        cout << "This is a rectangle with width " << width << " and height " << height << endl;
    }
};

int main() {
    // Runtime polymorphism
    Shape* shape1 = new Circle(5);   // Pointer of base type pointing to derived object
    Shape* shape2 = new Rectangle(4, 6);

    shape1->display();               // Calls Circle's display()
    cout << "Area: " << shape1->area() << endl << endl;  // Calls Circle's area()

    shape2->display();               // Calls Rectangle's display()
    cout << "Area: " << shape2->area() << endl << endl;  // Calls Rectangle's area()

    // Compile-time polymorphism (function overloading)
    Shape genericShape;
    genericShape.describe();
    genericShape.describe("It's a general shape.");

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
