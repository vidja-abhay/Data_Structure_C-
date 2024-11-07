#include <iostream>
using namespace std;

// Base class (grandparent)
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
};

// Derived class (parent)
class Mammal : public Animal {
public:
    void breathe() {
        cout << "I can breathe air!" << endl;
    }
};

// Derived class (child)
class Dog : public Mammal {
public:
    void bark() {
        cout << "I can bark! Woof woof!" << endl;
    }
};

int main() {
    Dog myDog;
    
    myDog.eat();     // Inherited from Animal (grandparent)
    myDog.breathe(); // Inherited from Mammal (parent)
    myDog.bark();    // Dog's own method
    
    return 0;
}