#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
};

// Derived class from Animal
class Mammal : public Animal {
public:
    void breathe() {
        cout << "I can breathe air!" << endl;
    }
};

// Another base class
class WingedAnimal {
public:
    void fly() {
        cout << "I can fly!" << endl;
    }
};

// Derived class using multiple inheritance
class Bat : public Mammal, public WingedAnimal {
public:
    void echolocate() {
        cout << "I can echolocate!" << endl;
    }
};

int main() {
    Bat myBat;
    
    myBat.eat();        // From Animal (grandparent)
    myBat.breathe();    // From Mammal (parent)
    myBat.fly();        // From WingedAnimal
    myBat.echolocate(); // Bat's own method
    
    return 0;
}