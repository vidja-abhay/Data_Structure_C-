#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
    
    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark! Woof woof!" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "I can meow! Meow meow!" << endl;
    }
};

// Derived class 3
class Cow : public Animal {
public:
    void moo() {
        cout << "I can moo! Moo moo!" << endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;
    Cow myCow;
    
    cout << "Dog:" << endl;
    myDog.eat();
    myDog.sleep();
    myDog.bark();
    
    cout << "\nCat:" << endl;
    myCat.eat();
    myCat.sleep();
    myCat.meow();
    
    cout << "\nCow:" << endl;
    myCow.eat();
    myCow.sleep();
    myCow.moo();
    
    return 0;
}