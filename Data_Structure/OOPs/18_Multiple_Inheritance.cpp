#include <iostream>
using namespace std;

// Base class 1
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
};

// Base class 2
class Flyable {
public:
    void fly() {
        cout << "I can fly!" << endl;
    }
};

// Derived class inheriting from both Animal and Flyable
class Bird : public Animal, public Flyable {
public:
    void chirp() {
        cout << "I can chirp!" << endl;
    }
};

int main() {
    Bird sparrow;
    
    sparrow.eat();   // Inherited from Animal
    sparrow.fly();   // Inherited from Flyable
    sparrow.chirp(); // Bird's own method
    
    return 0;
}