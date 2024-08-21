#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    virtual void makeSound() {
        cout << "The animal makes a sound" << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class
class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

    void makeSound() override {
        cout << "The dog barks: Woof! Woof!" << endl;
    }

    void displayBreed() {
        cout << "Breed: " << breed << endl;
    }
};

int main() {
    Animal genericAnimal("Generic", 5);
    Dog myDog("Buddy", 3, "Golden Retriever");

    cout << "Generic Animal:" << endl;
    genericAnimal.displayInfo();
    genericAnimal.makeSound();

    cout << "\nMy Dog:" << endl;
    myDog.displayInfo();
    myDog.makeSound();
    myDog.displayBreed();

    return 0;
}