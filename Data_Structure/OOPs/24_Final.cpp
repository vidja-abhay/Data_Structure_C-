#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base class display function." << endl;
    }
};

// The Derived class cannot be inherited further because it's marked 'final'
class Derived final : public Base {
public:
    void display() override {
        cout << "Derived class display function." << endl;
    }
};

// This will cause a compile-time error because Derived is final
// class FurtherDerived : public Derived {
// };

int main() {
    Derived obj;
    obj.display();  // Output: Derived class display function.
    return 0;
}


#include <iostream>
using namespace std;

class Base {
public:
    // Virtual function that cannot be overridden in further derived classes
    virtual void show() final {
        cout << "Base class show function." << endl;
    }
};

// Class can inherit from Base, but cannot override the show() function
class derived : public Base {
public:
    // Error: cannot override final function
    // void show() override {
    //     cout << "Derived class show function." << endl;
    // }
};

int main() {
    derived obj;
    obj.show();  // Output: Base class show function.
    return 0;
}
